#define _XOPEN_SOURCE 500

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "ht.h"

/* hash a string for a particular hash table. */
static int htHash(struct hashtable *hashtable, char *key)
{
        /* convert our string to an integer index */
        unsigned long int hashval;
        unsigned int i = 0;
        while (hashval < ULONG_MAX && i < strlen(key)) {
                hashval = hashval << 8;
                hashval += key[i];
                i++;
        }
        return hashval % hashtable->size;
}

/* create a key-value pair. */
static struct htEntry *htNewpair(char *key, void *value, int size)
{
        struct htEntry *newpair;

        if ((newpair = malloc(sizeof(struct htEntry))) == NULL)
                return NULL;

        if ((newpair->key = strdup(key)) == NULL)
                return NULL;

        if ((newpair->value = malloc(size)) == NULL)
                return NULL;
        memcpy(newpair->value, value, size);

        newpair->next = NULL;
        return newpair;
}

struct hashtable *htCreate(int size)
{
        if (size < 1) return NULL;

        struct hashtable *hashtable = NULL;
        if ((hashtable = malloc(sizeof(struct hashtable))) == NULL)
                return NULL;

        /* allocate pointers to the head nodes. */
        if ((hashtable->table = malloc(sizeof(struct htEntry *) * size)) == NULL)
                return NULL;
        int i;
        for (i = 0; i < size; i++)
                hashtable->table[i] = NULL;
        hashtable->size = size;
        return hashtable;
}

/* insert a key-value pair into a hash table. */
void htSet(struct hashtable *hashtable, char *key, void *value, int size)
{
        int bin = 0;
        bin = htHash(hashtable, key);

        struct htEntry *next = NULL;
        next = hashtable->table[bin];

        struct htEntry *last = NULL;
        while (next != NULL && next->key != NULL && strcmp(key, next->key) > 0) {
                last = next;
                next = next->next;
        }

        /* there's already a pair, let's replace that value. */
        if (next != NULL && next->key != NULL && strcmp(key, next->key) == 0) {
                free(next->value);
                next->value = malloc(size);
                memcpy(next->value, value, size);
        } else { /* nope, couldn't find it.  time to grow a pair. */
                struct htEntry *newpair = NULL;
                newpair = htNewpair(key, value, size);
                /* we're at the start of the linked list in this bin. */
                if (next == hashtable->table[bin]) {
                        newpair->next = next;
                        hashtable->table[bin] = newpair;
                        /* we're at the end of the linked list in this bin. */
                } else if (next == NULL) {
                        last->next = newpair;
                        /* we're in the middle of the list. */
                } else  {
                        newpair->next = next;
                        last->next = newpair;
                }
        }
}

char *htGet(struct hashtable *hashtable, char *key)
{
        int bin = htHash(hashtable, key);

        /* step through the bin, looking for our value. */
        struct htEntry *pair = hashtable->table[bin];
        while (pair != NULL && pair->key != NULL && strcmp(key, pair->key) > 0)
                pair = pair->next;

        /* did we actually find anything? */
        if (pair == NULL || pair->key == NULL || strcmp(key, pair->key) != 0)
                return NULL;
        else return pair->value;
}
