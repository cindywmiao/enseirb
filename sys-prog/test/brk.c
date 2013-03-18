#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
char *ptr;
printf("Changing allocation with brk()\n");
ptr = malloc(1);
printf("Before brk() call: %lu bytes free\n", coreleft());
brk(ptr+1000);
printf(" After brk() call: %lu bytes free\n", coreleft());
return 0;
}
