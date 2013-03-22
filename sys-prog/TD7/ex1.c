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
#define MAX 1000000
static int tab[MAX] = {0};
pthread_mutex_t mattr; 
void *ecrire(void *a){

  int i ,cpt,t;
  
  for(cpt = 0; cpt < 10 ; cpt ++){
    pthread_mutex_lock(&mattr);
    for(i = 0 ; i < MAX ; i++){
      tab[i]++; 
    }
    printf("Affiche le message ecrit!\n");
    sleep(0);
    pthread_mutex_unlock(&mattr);
  }
  return NULL;
}

void *lecture(void *a){
  int i,cpt;
  for(cpt = 0 ; cpt < 10; cpt++){
    pthread_mutex_lock(&mattr);
     int somme = 0;
     for(i = 0; i < MAX ; i++){
       somme += tab[i];
     }
     if(somme%2 != 0)
       printf("Affiche le message lecture, le somme de tableau A est %d!\n",somme);
     else
       printf("Le somme de tableau A est %d!\n",somme);
     sleep(1);
     pthread_mutex_unlock(&mattr);
  }
   return NULL;
}

int main(int argc, char *argv[]){
  
  int i;
  for (i = 0; i < MAX ; i++)
    tab[i] = 0;

  int nb_lecture = 4, nb_ecrire = 1;
  pthread_t pid[nb_lecture + nb_ecrire];
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  int x=getpid();
  void *ptr=(void *)&x;


  int ret = pthread_mutex_init(&mattr,NULL); 

  //  pthread_mutex_lock(&mattr);
  pthread_create(&pid[0], NULL, ecrire, ptr);
  for (i = 1 ; i <= nb_lecture ; i++)
    pthread_create(&pid[i], NULL, lecture, ptr);
  //pthread_mutex_unlock(&mattr);
  for(i = 0; i < nb_lecture + nb_ecrire; i++)
    pthread_join(pid[i], NULL);
  
  pthread_mutex_destroy(&mattr); 
  printf("Threads terminés.\n");
  return EXIT_SUCCESS;

}
