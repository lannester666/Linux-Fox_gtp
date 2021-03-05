//
// Created by 80670 on 2021/1/24.
//
#include<cstdio>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <cstring>
#include "iostream"
#include<unistd.h>
#include<pthread.h>
#define PORT 8888
#define MSG_SIZE 1024
using namespace std;
void* recv_data(int socket)
{
    char recv_buf[1024];
    memset(&recv_buf, 0 ,sizeof(recv_buf));
    recv(socket, recv_buf, 1024, 0);
    cout<<"receive data:"<<recv_buf<<endl;
}
void* send_data(int socket)
{
    char send_buf[1024];
    memset(&send_buf, 0 ,sizeof(send_buf));
    cin>>send_buf;
    cout<<"send message:"<<send_buf<<endl;
    send(socket, send_buf, 0 ,sizeof(send_buf));
}
//int main(int argc, char *argv[])
//{
//    int server_sock;
//    int client_sock;
//    int len;
//    struct sockaddr_in my_addr;
//    struct sockaddr_in remote_addr;
//    int sin_size;
////    char send_buf[1024];
////    char recv_buf[1024];
////    memset(&send_buf, 0,sizeof(send_buf));
////    memset(&recv_buf, 0, sizeof(recv_buf));
//    memset(&my_addr, 0, sizeof(my_addr));
//    my_addr.sin_family = AF_INET;
//    my_addr.sin_addr.s_addr = INADDR_ANY;
//    my_addr.sin_port = htons(8888);
//    server_sock = socket(PF_INET,SOCK_STREAM, 0);
//    bind(server_sock, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
//    listen(server_sock, 10);//监听队列长度为10
//    client_sock = accept(server_sock, (struct sockaddr *) &remote_addr, reinterpret_cast<socklen_t *>(&sin_size));
//    cout<<"receive connection ip:"<<remote_addr.sin_addr.s_addr<<"  port:"<<remote_addr.sin_port<<endl;
//    while(true) {
//        pthread_t thread[2];
//      pthread_create(&thread[0], NULL, reinterpret_cast<void *(*)(void *)>(send_data(client_sock)), NULL);
//        pthread_create(&thread[0], NULL, reinterpret_cast<void *(*)(void *)>(recv_data(client_sock)), NULL);
////        int n = recv(client_sock, recv_buf, MSG_SIZE, 0);
////        cout<<"receive message:"<<recv_buf<<endl;
////        cin>>send_buf;
////        if(strcmp(send_buf, "quit")==0)
////            break;
////        cout<<"send buf:"<<send_buf<<endl;
////        send(client_sock, send_buf, strlen(send_buf), 0);
//    }
//    close(client_sock);
//    close(server_sock);
//    return 0;
//}
