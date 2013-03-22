#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
    
void show_handler(int signo)
{
        printf("recieve signo =%2d\n",signo);
}
int main(int argc,char ** argv)
{
  
        int i;
	pid_t p = fork();
        struct sigaction act;

        act.sa_handler=show_handler;

        act.sa_flags = 0;
        sigemptyset(&act.sa_mask);

	for (i=0 ; i < 28 ; i++)
	  sigaction(i, &act, NULL);
   
	while(1){
	  sigsuspend(&act.sa_mask);
	}   
	
        return 0;
}
