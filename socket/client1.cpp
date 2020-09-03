#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
    int sock = socket(AF_INET,SOCK_STREAM,0) ;
    
    struct sockaddr_in servaddr ;
    memset(&servaddr,0,sizeof(servaddr)) ;

    servaddr.sin_family = AF_INET ;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1") ;
    servaddr.sin_port = htons(1235) ;

    connect(sock,(struct sockaddr*)&servaddr,sizeof(servaddr)) ;

    char readBuffer[40] ;
    char writeBuffer[40] ;

    while(1){
        memset(readBuffer,0,sizeof(readBuffer)) ;
        read(sock,readBuffer,sizeof(readBuffer)) ;
        printf("read from readBuffer: %s\n",readBuffer) ;

        memset(writeBuffer,0,sizeof(writeBuffer)) ;
        gets(writeBuffer) ;
        write(sock,writeBuffer,sizeof(writeBuffer)) ;
    }
    close(sock) ;
    return 0 ;
}