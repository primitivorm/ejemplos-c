// gcc -pthread -ofuga fuga.c
// utilice pmap para detectar fugas de memoria
// pmap PID | grep 10240 | wc -l
// ls /proc/PID/task | wc -l <- obtiene la cantidad de threads activos
// utilice pthread_join(pthread_t, void**) para reciclar el almacenamiento 
// privado asignado al thread
#include<stdio.h>
#include<pthread.h>

void *run() {
   pthread_exit(0);
}

int main () {
   pthread_t thread;
   int rc;
   long count = 0;
   while(1) {
      if(rc = pthread_create(&thread, 0, run, 0) ) {
         printf("ERROR, rc is %d, so far %ld threads created\n", rc, count);
         perror("Fail:");
         return -1;
      }
      count++;
   }
   return 0;
}
