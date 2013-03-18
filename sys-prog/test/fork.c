#include <stdio.h>
#include <stdlib.h>

int x = 3;
int j = 4;

void *function(void *arg){

  int i = (int)((intptr_t)arg);

  printf("%d:%d %d \n",i, x, j);
  j++;

  return NULL;
}

int main(){

  int status , i;

  pthread_t pid[2];

  pid_t child;

  int y = 0;

  for (i = 0; i < 2; i++){
    child = fork();
    if (child == 0){

      y = y + 10;

      if (fork() == 0)
	y = y + 100;
    }
    else
      {
	x = x * x;
      }
  }

  for (i = 0; i < 2; i++){
    int y2 = i+ y;
    pthread_create(&pid[i],NULL, function, (void*)((intptr_t)y2));
  }

  for (i = 0; i < 2; i++)
    pthread_join(pid[i],NULL);

  return 0;
}
