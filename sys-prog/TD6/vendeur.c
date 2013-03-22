#include <stdio.h>

#define MAX 1000
static int nb;
void *decrementer(void *a){
  if(nb != 0)
    nb--;

}

void *incrementer(void *a){
  if(nb != MAX)
    nb++;

}

int main(void){

  int nb_thread = 8;
  int i;
  pthread_t pid[nb_thread];

  void *ptr = (void*)&getpid();

  for (i = 0; i < 4; i++)
    pthread_create(&pid[i],NULL,incrementer,ptr);

  for( i = 4; i < 8; i++)
    pthread_creat(&pid[i],NULL,decrementer,ptr);



  return 1;
}
