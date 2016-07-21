#include "khash.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct str_val{
  char *ptr;
  size_t len;
}str_val;

KHASH_MAP_INIT_INT64(env, str_val);
typedef khash_t(env) lat_env;
lat_env *globals;

static int env_set(lat_env *env, str_val* name, str_val val){
    int r;
    khiter_t k;
    if(!globals){
        globals = kh_init(env);
    }
    env = globals;
    k = kh_put(env, env,(intptr_t)name, &r);
    if( r<= 0) return 1;

    kh_value(env, k) = val;
    return 0;
}

int env_get(lat_env *env, str_val* name, str_val *val){
    khiter_t k;
    k = kh_get(env, env, (intptr_t)name);
    if(k == kh_end(env)) return 1;
    *val = kh_value(env, k);
    return 0;
}

/*
static str_val*
str_new(const char *p, size_t len)
{
    str_val *str;
    char *buf;
    str = malloc(sizeof(str_val)+len+1);
    buf = (char*)&str[1];
    if (p) {
      memcpy(buf, p, len);
    }
    else {
      memset(buf, 0, len);
    }
    buf[len] = '\0';
    str->ptr = buf;
    str->len = len;
    return str;
}
*/

int main(){
    str_val *key = malloc(sizeof(str_val));
    str_val *value = malloc(sizeof(str_val));

    key->ptr = "gato";
    value->ptr = "negro";

    printf("key = %s\n", key->ptr);
    printf("value = %s\n", value->ptr);

    env_set(globals, key, *value);

    str_val *otro = malloc(sizeof(str_val));
    env_get(globals, key, otro);

    printf("otro valor = %s\n", otro->ptr);

    return 0;

}
