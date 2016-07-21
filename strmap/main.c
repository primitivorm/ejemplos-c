#include "strmap.h"
/*
 * http://pokristensson.com/strmap.html
 */

int main(int argc, char *argv[])
{

    StrMap *sm;
    char buf[255];
    int result;

    sm = sm_new(10);
    if (sm == NULL)
    {
        /* Handle allocation failure... */
    }
    /* Insert a couple of string associations */
    sm_put(sm, "application name", "Test Application");
    sm_put(sm, "application version", "1.0.0");
    /* Retrieve a value */
    result = sm_get(sm, "application name", buf, sizeof(buf));
    if (result == 0)
    {
        /* Handle value not found... */
    }
    printf("value: %s\n", buf);

    /* When done, destroy the StrMap object */
    sm_delete(sm);

    return 0;
}




