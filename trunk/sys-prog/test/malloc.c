#include <stdio.h>
#include <stdlib.h>

int t[10];
int main(void){

  int s = 0;

  void *p = malloc(10);
  printf("Code: %p Data: %p Heap: %p, %p Stack: %p", main,t, sbrk(0),p,&s);

  return 0;

}
