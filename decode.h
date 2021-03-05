//
// Created by 80670 on 2021/1/27.
//
#ifndef GO_TCP_DECODE_H
#define GO_TCP_DECODE_H
#include "string"
#include "fstream"
using namespace std;
void decode_protocol(int,char *,ofstream&);
//string encode_gtp(int,string);
string find_next(int *,string);
string find_next_location(int* pointer,string location);
const char* sort_AFPLAY(char *,ofstream&);
void sort_FAMOVE(int,string,ofstream&);
void sort_FARESULT(int,string);
void sort_FARULE(int,string);
void sort_FASKIP(int,string);
void sort_FASTATUS(int,string,string*);
void sort_FATIMELEFT(int,string,string);
bool FOXPKG_CalCheckSum(string,int,string&);
//int main(int argc, char *argv[]);
#endif //GO_TCP_DECODE_H
