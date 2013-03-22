#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#define NUM 8
#define REPS 100

sem_t sem[NUM];
int philo[NUM];
int baguettes[NUM];
void manger(int a){
  if(baguettes[a] == 1 && baguettes[(a+1)%NUM] == 1)
    philo[a] = 1; 
  sleep(1);}

void take_fork(int a){if(baguettes[a] == 0)baguettes[a] = 1;}

void put_fork(int a){if(baguettes[a] == 1)baguettes[a] = 0;}

void *philosopher(void *i){
  int a = *(int *)i;
  int j;

  //printf ("%d\n", a);
  for(j=0; j<REPS; j++)
    {
      /* sem_wait(&sem[a]); */
      /* sem_wait(&sem[(a+1)%NUM]); */
      take_fork(a);
      take_fork((a+1)%NUM);
      manger(a);
      put_fork(a);
      put_fork((a+1)%NUM);
      /* sem_post(&sem[a]); */
      /* sem_post(&sem[(a+1)%NUM]); */
      philo[a] = 0;
      printf("philosopher %d, fork %d , fork2 %d \n", a, a,(a+1)%NUM);
    }
}
int main(int argc, char * argv[]){

  int i;
  int id[NUM];
  pthread_t pid[NUM];
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  for(i = 0; i < NUM ; i++) {
    philo[i] = 0;
    id[i] = i;
  }
  
  for(i = 0; i < NUM; i++)
    baguettes[NUM] = 0;

  for(i = 0 ; i < NUM; i++)
    sem_init(&sem[i],0,1);

  for(i = 0 ; i < NUM; i++) {
    pthread_create(&pid[i], NULL, philosopher ,&id[i]);
  }

  for(i = 0 ; i < NUM ; i++)
    pthread_join(pid[i],NULL);

  for(i = 0 ; i < NUM ; i++)
    sem_close(&sem[i]);

  printf("Threads terminés.\n");

  return EXIT_SUCCESS;

}
