//
// Created by 80670 on 2021/2/1.
//

#ifndef GO_TCP_SIMUGTP_H
#define GO_TCP_SIMUGTP_H
#include "string"
using namespace std;
int acceptsocket(int);
static void child(int,int);
int conn_socket(char*,int);
int main(int argc, char **);
static void parent(int,int);
int socketserver(int,int);
int start_aicom();
void* start_routine_io(void *);
void* start_routine_sock(void *);
int start_socket_listenyehu();
void * thread_function(void *);
int write_io(int,string);
int write_sock(int,const char *);
#endif //GO_TCP_SIMUGTP_H
