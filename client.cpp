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
#define PORT 8888
#define MSG_SIZE 1024
using namespace std;

//int main(int argc, char *argv[])
//{
////    WSADATA wsadata;
////    WSAStartup(MAKEWORD(2, 2), &wsadata);
////    SOCKADDR_IN addrSrv;
////    addrSrv.sin_family = AF_INET;
////    addrSrv.sin_port = htons(PORT);
////    addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
////
////    SOCKET socketclient = socket(AF_INET, SOCK_STREAM , 0);
////    if(SOCKET_ERROR == socketclient)
////    {cout<<"socket create failed"<<endl;
////    return 0;}
////    auto con = connect(socketclient, (struct sockaddr*)&addrSrv, sizeof(addrSrv));
////    if(con==SOCKET_ERROR)
////    {
////        cout<<"connection error"<<endl;
////        return 0;
////    }
////    char buff[1024];
////    memset(buff, 0 , sizeof(buff));
////    {
////        recv(socketclient, buff, sizeof(buff), 0);
////        cout<<"receive data from server"<<buff<<endl;
////    }
////    char buffs[] = "send from client";
////    while(1) {
////        cin>>buffs;
////        cout<<buffs<<endl;
////        send(socketclient, buffs, sizeof(buffs), 0);
////    }
////    closesocket(socketclient);
////    WSACleanup();
////    system("pause");
////    return 0;
//    int client_sock;
//    int len;
//    struct sockaddr_in remote_addr;
//    char send_buf[1024];
//    char recv_buf[1024];
//    memset(&send_buf, 0,sizeof(send_buf));
//    memset(&recv_buf, 0, sizeof(recv_buf));
//    memset(&remote_addr,0,sizeof(remote_addr));
//    remote_addr.sin_family = AF_INET;
//    remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//    remote_addr.sin_port = htons(8888);
//    client_sock = socket(PF_INET, SOCK_STREAM, 0);
//    connect(client_sock, (struct sockaddr*)&remote_addr, sizeof(struct sockaddr));
//    while(true)
//    {
//        cout<<"send anything here"<<endl;
//        cin>>send_buf;
//        if(strcmp(send_buf, "quit")==0)
//            break;
//        cout<<"send buf:"<<send_buf<<endl;
//        send(client_sock, send_buf, strlen(send_buf), 0);
//        recv(client_sock, recv_buf, 1024, 0);
//        cout<<"receive buf:"<<recv_buf<<endl;
//    }
//    close(client_sock);
//    return 0;
//}
