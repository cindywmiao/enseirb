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
    int i;
  
    int vs_fifo_id = 0;
    int vs_fifo_rd = 0;

    int vc_fifo_id[argc -1];
    int vc_fifo_rd = 0;

    int idclient[argc -1];
    char buffer[MAX_SIZE];
    char FIFOClient[MAX_SIZE];


    /* creat the files */
    if (mknod(FIFOServeur, S_IFIFO | 0666, 0) == -1){
      perror("mknod Serveur");
      exit(1);
    } 

    for(i = 1; i < argc ; i++){
      strcpy(FIFOClient, "./FIFO/");
      strcat(FIFOClient, argv[i]);
      
      if(mknod(FIFOClient, S_IFIFO | 0666,0) == -1){
	perror("mknod Client");
	exit(1);
      }
      idclient[i - 1] = i;
     
    }

    /* open the files */
    if((vs_fifo_id = open(FIFOServeur, O_RDONLY)) == -1 ){
	perror("open Serveur");
	exit(1);
      }
    
    for(i = 1; i < argc ; i++){
      strcpy(FIFOClient, "./FIFO/");
      strcat(FIFOClient, argv[i]);
      if((vc_fifo_id[i - 1] = open(FIFOClient , O_WRONLY)) == -1){
	perror("open Client");
	exit(1);
      }
    }

    char id[MAX_SIZE];

    do
    {
	vs_fifo_rd = read(vs_fifo_id, buffer, MAX_SIZE * sizeof(char));
	write(0, buffer, vs_fifo_rd);

	strcpy(id,"");
	int j = 0;
	while(j < strlen(buffer) && (buffer[j] != ':') && j < MAX_SIZE)
	  {
	    id[j] = buffer[j];
	    j++;
	  }
	id[j] = '\0';
	
	
	for(i = 0; i < argc - 1 ; i++){
	  
	  if(!(strcmp(id,argv[i + 1])) ==0)
	      write(vc_fifo_id[i], buffer, vs_fifo_rd * sizeof(char));
	}

    }while (vs_fifo_rd != 0);


    /* close the files serveur and clients*/
    close(vs_fifo_id);
    unlink(FIFOServeur);
    
    for(i = 0; i < argc - 1 ; i++){
      close(vc_fifo_id[i]);
      strcpy(FIFOClient, "./FIFO/");
      strcat(FIFOClient, argv[i]);
      unlink(FIFOClient);
      }

    return EXIT_SUCCESS;
}
