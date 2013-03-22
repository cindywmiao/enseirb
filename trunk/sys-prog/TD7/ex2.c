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
int nlect = 0;
pthread_mutex_t mattr;
pthread_mutex_t mattr_clu;
sem_t *sem[4];
sem_t *s;
void *ecrire(void *a){
  int i ,cpt,t;
  for(cpt = 0; cpt < 10 ; cpt ++){
    pthread_mutex_lock(&mattr);
    for(i = 0 ; i < MAX ; i++){
      tab[i]++;
      /* for(t = 0; t < 4 ; t++) */
      /* 	sem_post(sem[t]); */
    }
    /* for (i = 0; i < 4; i++) */
    /*   sem_wait(s); */
    printf("Affiche le message ecrit!\n");
    sleep(0);
    pthread_mutex_unlock(&mattr);
  }
  return NULL;
}

void *lecture(void *semt){
  
  pthread_mutex_lock(&mattr);
  nlect++;
  if(nlect == 1)
    pthread_mutex_lock(&mattr_clu);
  pthread_mutex_unlock(&mattr);
  int i,cpt;
  for(cpt = 0 ; cpt < 10; cpt++){
    pthread_mutex_lock(&mattr);
     int somme = 0;
     for(i = 0; i < MAX ; i++){
       /* sem_wait(s); */
       somme += tab[i];
     }
     if(somme%2 != 0)
       printf("Affiche le message lecture, le somme de tableau A est %d!\n",somme);
     else
       printf("Le somme de tableau A est %d!\n",somme);
     nlect--;
     if(nlect == 0)
       pthread_mutex_unlock(&mattr_clu);
     sleep(1);
     pthread_mutex_unlock(&mattr);
     /* sem_post(s); */
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
  
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  int ret = pthread_mutex_init(&mattr,NULL);
  pthread_mutex_init(&mattr_clu,NULL);
  
  /* sem_init(s,0,1); */
  
  /* for(i = 0 ; i < pthread_lecture; i++) */
  /*   sem_init(sem[i],0,4); */
  
  for(i = 0 ; i < pthread_ecrit; i++)
    pthread_create(&pid[i], NULL, ecrire, ptr);
  
  for(i = 0 ; i < pthread_lecture; i++)
    pthread_create(&pid[i + 1], NULL, lecture, ptr);
  
  ecrire(NULL);

  for(i = 0 ; i < pthread_size - 1; i++)
    pthread_join(pid[i],NULL);
  
  /* for(i = 0 ; i < pthread_lecture ; i++) */
  /*   sem_close(sem[i]); */

  /* sem_close(s); */
  pthread_mutex_destroy(&mattr);
  printf("Threads terminés.\n");

  return EXIT_SUCCESS;

}
