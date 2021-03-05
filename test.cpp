//
// Created by 80670 on 2021/2/1.
//
#include <string>
#include "cstring"
#include"iostream"
using namespace std;
bool FOXPKG_CalCheckSum(
       string buf, // 数据缓冲区
        int BufSize, // 缓冲区字节大小
        char &byteCheckSum // 带出校验和
)
{
    auto *buf1 = (unsigned char *)buf.c_str();
// 参数有效性
    if (buf1==NULL || BufSize==0)
    {
        return false;
    }
// 计算异或和的值
    char checkSum = buf1[0];
    for (int i=1; i<BufSize; i++)
    {
        checkSum ^= buf1[i];
    }
// 输出结果
    byteCheckSum = checkSum;
    return true;
}
int main()
{
    string buf = "FASTATUS,0";
    int bufsize = buf.size();
    char check;
    if(FOXPKG_CalCheckSum(buf,bufsize,check))
        cout<<"%x"<<check<<endl;
    return 0;
}
