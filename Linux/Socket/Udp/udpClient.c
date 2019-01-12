#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <error.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
int main()
{
    //1. 创建套接字
    int socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketfd == -1) {
        perror("error for socket");
        return -1;
    }


    //2. 绑定套接字 //客户端不推荐绑定
    /*struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = inet_addr("10.0.6.118");
    socklen_t len = sizeof(client_addr);
    int ret = bind(socketfd, (struct sockaddr*)&client_addr, len);
    if (ret == -1) {
        perror("error for bind");
        return -1;
    }
    */
    struct sockaddr_in service_addr;
    service_addr.sin_family = AF_INET;
   // service_addr.sin_addr.s_addr = inet_addr("10.0.6.118");
    service_addr.sin_addr.s_addr = inet_addr("172.16.58.243");
    service_addr.sin_port = htons(7777);
    socklen_t len = sizeof(service_addr);
    while(1) {
        //3. 发送信息
        char buff[1024] = {0};
        printf("You want to say:");
        scanf("%s", buff);
        int sendret = sendto(socketfd, buff, strlen(buff), 0, (struct sockaddr*)&service_addr, len);
        if (sendret == -1) {
            perror("error for sendto");
            return -1;
        }
    //    printf("send end\n");
        //4. 接收信息
        memset(buff, 0, 1024);
        recvfrom(socketfd, buff, 1023, 0, (struct sockaddr*)&service_addr, &len);
        printf("Service say: %s\n", buff);
    }

    //5. 关闭套接字
    close(socketfd);
    return 0;
}
