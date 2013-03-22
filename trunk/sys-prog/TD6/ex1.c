#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

static int nb;
sem_t *sem;
void *start (void *a){


  int vendus = 0;
  int done = 0;
  while(!done){
    
   sem_wait(sem);
   if(nb>0){
     sleep(0);
     nb --;
     vendus ++;
   }
   else 
     done = 1;
   sem_post(sem);
 
  }
  
  printf("Nb billets vendus : %d\n",vendus);


  return NULL;
}

int main(int argc, char *argv []){

  int x=getpid();
  pthread_t pid[8];  
  void *ptr=(void *)&x;

  int i;
  nb = atoi( argv[1] );
  printf("%d\n",nb);
  /* pthread_attr_t attr; */
  /* pthread_attr_init(&attr); */
  sem = sem_open("semaphor",O_CREAT,0666,1);
  for(i=0;i<8;i++){
    pthread_create(&pid[i],NULL,start,ptr);
  }
  for(i=0;i<8;i++){
    pthread_join(pid[i],NULL);
    //printf("e");
  }
    sem_close(sem);
    sem_unlink("semaphor");

  printf("Threads terminés.\n");

  return EXIT_SUCCESS;
}
