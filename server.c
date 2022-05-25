#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdlib.h>

void Perror(const char * s) {
  perror(s);
  exit(EXIT_FAILURE);
}

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0); //TCP  
  int backlog = 100;
  short port = 9527; //port  
  struct sockaddr_in servaddr;
  servaddr.sin_family = AF_INET; //IPv4  
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //Represents that the IP address is selected by the kernel  
  servaddr.sin_port = htons(port);

  //int flag = 1;
  //if (-1 == setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, & flag, sizeof(flag))) {
    //Perror("setsockopt fail");
  //}

  int res = bind(sockfd, (struct sockaddr * ) & servaddr, sizeof(servaddr));
  if (0 == res)
    printf("server bind success, 0.0.0.0:%d\n", port);
  else {
    Perror("bind fail");
  }

  if (-1 == listen(sockfd, backlog)) {
    Perror("listen fail");
  }

  //Waiting for connection  
  struct sockaddr_in cliaddr;
  socklen_t len = sizeof(cliaddr);
  int connfd = accept(sockfd, (struct sockaddr * ) & cliaddr, & len);
  if (-1 == connfd) {
    Perror("accept fail");
  }

  //Resolving Client Address  
  char buff[INET_ADDRSTRLEN + 1] = {
    0
  };
  inet_ntop(AF_INET, & cliaddr.sin_addr, buff, INET_ADDRSTRLEN);
  uint16_t cli_port = ntohs(cliaddr.sin_port);
  printf("connection from %s, port %d\n", buff, cli_port);

  //Close sockfd of bind  
  close(sockfd);

  //  
  sleep(12);

  return 0;
}
