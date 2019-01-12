#include <stdio.h>
#include <error.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    //1. 创建套接字
    //int socket(int domain, int type, int protocol);
    int socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    //    地址域：AF_INET　　　ipb4 协议
    //    类型：  数据报  SOCK_DGRAM
    //    协议：    IPPROTO_UDP  UDP 协议
    if (socketfd == -1) {   //失败返回
        perror("error for socket");
        return -1;
    }
    //2. 绑定套接字
    //int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    //　sockfd  文件描述符
    //  addr 套接字绑定的地址
    //          用sockaddr_in 来定义　使用时强转
    //  addrlen 地址信息长度
    //  返回值　0   失败－１
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;      //协议簇
    addr.sin_port = htons(7777);
    addr.sin_addr.s_addr = inet_addr("10.0.6.118");
    socklen_t len = sizeof(struct sockaddr_in);
    int ret;
    ret = bind(socketfd, (struct sockaddr*) &addr, len);
    if (ret == -1) {
        perror("error for bind");
        return -1;
    }
    while(1) {
        //3. 服务器先接收数据
        //ssize_t recvfrom(int sockfd, void *buf, size_t len, 
        //      int flags,struct sockaddr *src_addr, socklen_t *addrlen);
        //  sockfd: 套接字描述符---确定从哪里获取数据
        //  buf：   用于接收数据
        //  len：   接收的数据长度
        //  flags： 默认赋0---阻塞接收（没数据就一直等待）
        //  src_addr：  数据从哪里来，对端地址信息
        //  addrlen：   地址信息长度（输入输出复合参数）
        //  返回值：实际接收的数据长度      失败：-1
        char buff[1024] = {0};
        struct sockaddr_in client_addr;
        recvfrom(socketfd, buff, 1023, 0, (struct sockaddr*) &client_addr, &len);
        printf("client say: %s\n", buff);
        //4. 回信息
        memset(buff, 0, 1024);
        printf("You want to say:");
        scanf("%s", buff);
        //ssize_t sendto(int sockfd, const void *buf, size_t len, 
        //  int flags,struct sockaddr *dest_addr, socklen_t addrlen);
        //  dest_addr:  目的端地址信息
        //  addrlen：   地址信息长度
        sendto(socketfd, buff, strlen(buff), 0, (struct sockaddr*) &client_addr, len);
    }
    //5. 关闭套接字
    close(socketfd);
    return 0;
}

