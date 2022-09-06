#include<stdio.h>
#include<strings.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<betinet/in.h>
#define PORT 5000
#define MAXLINE 1000

int main(){
    char buffer[100];
    char *message = "Hello Client";
    int listenfd, len;
    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizeof(servaddr));
    //Creation of a UDP Socket
    listenfd = socket(AF_INET, SOCK_DGRAM,0)
    servaddr.sin_addr.s_addr = hton1(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family=AF_INET;
    //Bind server adress to socket descriptor
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    //receive the datagram
    len = sizeof(cliaddr);
    int n = recvfrom(listenfd, buffer, sizeoff(buffer),0,(struct sockaddr*)&cliaddr,&len);
    buffer[n] = '\0';
    puts(buffer);
    //send response
    sendto(listenfd,message,MAXKINE,0,(struct sockaddr*)&cliaddr, sizeof(cliaddr));

}