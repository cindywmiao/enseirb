#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.c>
#define chaine "0123456789"
#define SIZE 128
int main(void){

  int f = open("./test",O_RDWR);
  if(f == -1)
    {
      perror("open");
      exit(1);
    }

  char *A = mmap(NULL,SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,f,0);
  if(A == MAP_FAILED){
    perror("mmap");
    exit(1);
  }

  int i;
  for(i = 0; i < 10; i++)
    A[10 + i] = chaine[i];

  munmap(A,SIZE);

  return 0;
}
