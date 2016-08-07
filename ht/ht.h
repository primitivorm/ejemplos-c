#ifndef HT_H
#define HT_H

struct htEntry {
        char *key;
        void *value;
        struct htEntry *next;
};

struct hashtable {
        int size;
        struct htEntry **table;
};

struct hashtable *htCreate(int size);                                      /* Create a new hashtable. */
void htSet(struct hashtable *hashtable, char *key, void *value, int size); /* Insert a key-value pair into a hash table. */
char *htGet(struct hashtable *hashtable, char *key);                       /* Retrieve a key-value pair from a hash table. */

#endif /* HT_H */
