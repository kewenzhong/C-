#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //具体的IP地址
    serv_addr.sin_port = htons(1235);  //端口
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    //进入监听状态，等待用户发起请求
    listen(serv_sock, 20);
    char sendBuffer[40];
    char receBuffer[40];

    //接收客户端请求
    // struct sockaddr_in clnt_addr;
    // socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)NULL, NULL);

    while(1){
        //向客户端发送数据
        strcpy(sendBuffer,"hello client") ;
        write(clnt_sock, sendBuffer, sizeof(sendBuffer));
    
        memset(receBuffer,0,sizeof(receBuffer)) ;
        read(clnt_sock,receBuffer,sizeof(receBuffer)-1) ;
        printf("%s\n",receBuffer) ;
        //关闭套接字

    }
    close(clnt_sock);
    close(serv_sock);

    return 0;
}