#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 7000
#define MAX 1024
#define CHK(X) if((X) == -1) { perror( #X); exit(1); } \

void echo(int s){
  int n;
  char buffer[MAX];
  while(1){
    n = read(s,buffer,MAX);
    if(strstr(buffer, "quit")) break;
    write(s,buffer,n);
  }
}

int main(int argc, char * argv[]){
  int s2;
  struct sockaddr_in serversockaddr;
  int port = PORT;

  if (argc == 2) port = atoi(argv[1]);
 
  int server = socket(AF_INET,SOCK_STREAM,0);
  serversockaddr.sin_family = AF_INET;
  serversockaddr.sin_addr.s_addr = INADDR_ANY;
  serversockaddr.sin_port = htons(port);
  
  CHK(bind(server, (struct sockaddr *)&serversockaddr, sizeof(serversockaddr)));
  printf("socket has port %d\n", ntohs(serversockaddr.sin_port));

  listen(server,8);
  s2 = accept(server,0,0);

  //echo

  printf("Connexion accepted. Closing...\n");
  close(s2);
  close(server);
  printf("Les bases d'un serveur terminée!\n");
  return 0;
}
