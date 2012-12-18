#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 1024
#define FIFOServeur "./FIFO/versserveur"

int main(int argc, char * argv[])
{
    int vs_fifo_id = 0;
    int vs_fifo_rd = 0;

    int vc_fifo_id = 0;
    int vc_fifo_rd = 0;

    char buffer[MAX_SIZE] = "";
    char Buffer[MAX_SIZE] = "";
    char FIFOClient[MAX_SIZE] = "./FIFO/";
    
    strcat(FIFOClient,argv[1]);
    

    if((vs_fifo_id = open(FIFOServeur, O_WRONLY)) == -1 ||
       (vc_fifo_id = open(FIFOClient , O_RDONLY)) == -1 ){
      perror("open");
      exit(1);
    }

    pid_t pid = fork();
    if(pid < 0)
      {
	perror("fork");
	exit(1);
      }
    else if(pid >0)
      { 
	do
	  {
	   
	    vs_fifo_rd = read(STDIN_FILENO, buffer, MAX_SIZE);
	    strcpy(Buffer,argv[1]);
	    strcat(Buffer,": ");
	    strcat(Buffer, buffer);
	    write(vs_fifo_id, Buffer, (strlen(argv[1]) + 2 + vs_fifo_rd) * sizeof(char));
	  }while (vs_fifo_rd != 0);
      }
    else
      {
	do
	  {
	    vc_fifo_rd = read(vc_fifo_id, buffer, MAX_SIZE * sizeof(char));
	    write(STDOUT_FILENO, buffer, vc_fifo_rd * sizeof(char)); 
	  }while (vc_fifo_rd != 0);
      }
   

    close(vs_fifo_id);
    close(vc_fifo_id);

    unlink(FIFOServeur);
    unlink(FIFOClient);

    return EXIT_SUCCESS;
}
