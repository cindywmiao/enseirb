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

#define MAX 10000
static int tab[MAX];
sem_t sem_ecrire;
sem_t sem_lecture;
void *ecrire(void *a){

  int i ,cpt,t;
  for(cpt = 0; cpt < 10 ; cpt ++){
    for(i = 0 ; i < MAX ; i++){
      tab[i]++;
    } 
    printf("Affiche le message ecrit!\n");
    sleep(1);
  }
  return NULL;
}

void *lecture(void *semt){
 
  int i,cpt;
  for(cpt = 0 ; cpt < 10; cpt++){
     int somme = 0;
     for(i = 0; i < MAX ; i++){
       somme += tab[i];
     }
     if(somme%2 != 0)
       printf("Affiche le message lecture, le somme de tableau A est %d!\n",somme);
     else
       printf("Le somme de tableau A est %d!\n",somme);
     sleep(1);
  }
  return NULL;
}

int main(int argc, char *argv[]){
  int i;
  for(i = 0 ; i < MAX ; i++)
    tab[i] = 0;

  int x=getpid();
  void *ptr=(void *)&x;

  
  int pthread_lecture = 4;
  int pthread_ecrit = 1;
  int pthread_size = pthread_lecture + pthread_ecrit;
  pthread_t pid[pthread_lecture + pthread_ecrit];
  

  for(i = 0 ; i < pthread_lecture; i++)
    pthread_create(&pid[i], NULL, lecture, ptr);
  
  for(i = 0 ; i < pthread_ecrit; i++)
    pthread_create(&pid[i + pthread_lecture], NULL, ecrire, ptr);
  
  ecrire(NULL);

  for(i = 0 ; i < pthread_size - 1; i++)
    pthread_join(pid[i],NULL);

  printf("Threads terminés.\n");

  return EXIT_SUCCESS;

}
