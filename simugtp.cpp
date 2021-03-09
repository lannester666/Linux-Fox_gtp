
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include "decode.h"
#include "simugtp.h"
#include "fstream"
#include <sys/prctl.h>
#include "iostream"
//协议解析
using namespace std;
//需要全局保存写管道（给ai）和写网络（给野狐）,备使用
int m_out = 0;
int m_in = 0;
int m_clnt_socket = 0;
ofstream outfile;
//read_socket函数
int write_io(int out, string s){
//    cout<<"write_io receive"<<s<<endl;
    int n=s.length();
    char seStr[n];
    strcpy(seStr, s.c_str());
    strcat(seStr, "\n");
//    cout<<"write_io receive"<<seStr<<endl;
    write(out, seStr, strlen(seStr));
    return 0;
}

//int conn_socket(char *ip, int port){
//    //创建套接字
//    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    //向服务器（特定的IP和端口）发起请求
//    struct sockaddr_in serv_addr;
//    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
//    serv_addr.sin_family = AF_INET;  //使用IPv4地址
//    //serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
//    serv_addr.sin_addr.s_addr = inet_addr(ip);  //具体的IP地址
//    //serv_addr.sin_port = htons(1234);  //端口
//    serv_addr.sin_port = htons(port);  //端口
//    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
//    return sock;
//}

//write_socket函数
int write_sock(int sockfd, const char* s){
    if(sockfd != 0) {
        return write(sockfd, s, strlen(s));
    }
    else {
        return -1;
    }
}

void *start_routine_io( void *ptr) 
{
    char reStr[256];
//    int in = *(int *)ptr;
	while (1)
	{
    	read(m_in, reStr, 256);
        //此处需要处理协议
        const char* s=sort_AFPLAY(reStr,outfile);
        if(strcmp(s,"")==0)
        {
            cout<<"校验出错或暂时不实现的命令"<<endl;
            continue;
        }
        cout<<s<<endl;
        cout<<"write_sock return "<<write_sock(m_clnt_socket,s)<<endl;
	}
}

void *start_routine_sock( void *ptr) 
{
    char str[256];
    int fd = *(int *)ptr;
    while (1){

        read(fd, str, sizeof(str));
        //此处需要处理接收到的信息，然后

        printf("client send: %s\n",str);
        decode_protocol(m_out,str,outfile);
//        strcat(str, "+ACK");
//        write_io(m_out, str);
    }
}

//socket client包装

//线程1函数，用socket server监听野狐客户端命令，监听到了，就使用write(out, seStr, strlen(seStr));
//线程2函数，监听ai发过来的standard i/o，用的read，收到之后，协议处理，socker client发给野狐客户端

int start_aicom(){
    int res;
    pthread_t a_thread;
    void *thread_result;
 
    res = pthread_create(&a_thread, NULL, start_routine_io, (void *)0);
    if(res != 0) {
        perror("\nThread creation failed!\n");
        exit(EXIT_FAILURE);
    }
}

int socketserver(int serv_sock, int port){
	//初始化socket元素
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
//	serv_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);

	//绑定文件描述符和服务器的ip和端口号
	bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	//进入监听状态，等待用户发起请求
	listen(serv_sock, 20);
    return 0;
}

int acceptsocket(int serv_sock){
	//接受客户端请求
	//定义客户端的套接字，这里返回一个新的套接字，后面通信时，就用这个clnt_sock进行通信
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    return clnt_sock;
}

void *thread_function(void *arg)
{
	//创建套接字
	int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    socketserver(serv_sock, 1234);

    while(1){
        int clnt_sock = acceptsocket(serv_sock);
        m_clnt_socket=clnt_sock;
        pthread_t thread; //定义一个线程号
        pthread_create(&thread,NULL,start_routine_sock,(void *)&clnt_sock);
//        start_routine_sock((void *)&clnt_sock);
//1.心跳信息
    }
 
	close(serv_sock);
}
 

int start_socket_listenyehu()
{
    int res;
    pthread_t a_thread;
    void *thread_result;
 
    res = pthread_create(&a_thread, NULL, thread_function, (void *)0);
    if(res != 0) {
        perror("\nThread creation failed!\n");
        exit(EXIT_FAILURE);
    }
}
 

static void
parent(int in, int out)
{
    m_out = out;
    m_in = in;

    char ip[256]="192.168.96.9";
    int port = 1234; 
    //需要链接野狐，如果链接失败，是有问题的
//    m_clnt_socket = conn_socket(ip, port);
    //启动两个线程
    //线程1，起一个socket server/tcp
    start_socket_listenyehu();
    //线程2，read(in, reStr, 256);
//    m_clnt_socket = conn_socket(ip, port);

    start_aicom();
    sleep(-1);
}

static void child(int in, int out)
{
    dup2(in, STDIN_FILENO);
    dup2(out, STDOUT_FILENO);
    execl("/usr/anaconda3/bin/python3", "python3", "/home/zty/go/code/run_gtp.py", (int*)0);
    //execl("/home/xgs/temp/t1c", "t1c", (int*)0);
}

int main(int argc, char *argv[])
{
    outfile.open("data.dat");
    pid_t pid;
    int p2cfds[2];
    int c2pfds[2];

    int i1=pipe(p2cfds);
    int i2=pipe(c2pfds);


    pid = fork();
    if (pid < 0) {
        printf("error in fork!");
    }
    else if (pid == 0) {
        prctl(PR_SET_PDEATHSIG,SIGHUP);
        child(p2cfds[0], c2pfds[1]);
    } else {
        parent(c2pfds[0], p2cfds[1]); 
    }

    return 0;
}

