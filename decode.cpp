//
// Created by 80670 on 2021/1/27.
//

#include "decode.h"
#include "cstdio"
#include "iostream"
#include "cstring"
#include "simugtp.h"
#include "sstream"
#include "algorithm"
#include "fstream"
using namespace std;
template <class T>
int getArrayLen(T& array)
{
    return (sizeof(array) / sizeof(array[0]));
}
int move;//全局变量代表手数；
string g_color;//全局变量代表ai棋子颜色；
bool FOXPKG_CalCheckSum(
        string buf, // 数据缓冲区
        int BufSize, // 缓冲区字节大小
        string &use // 带出校验和
)
{
    auto* buf1 = (unsigned char*)buf.c_str();
    // 参数有效性
    if (buf1 == NULL || BufSize == 0)
    {
        return false;
    }
    // 计算异或和的值
    char checkSum = buf1[0];
    for (int i = 1; i < BufSize; i++)
    {
        checkSum ^= buf1[i];
    }
    // 输出结果
    string s;
    stringstream ss;
    ss << hex << (int)checkSum;
    ss >> s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    if(s.length()==1)
        s='0'+s;
    return true;
}
string find_next(int* pointer,string gtp)
{
    //    cout<<pointer<<" "<<*pointer<<endl;
    *pointer = *pointer + 1;
    int start = *pointer;
    //    cout<<pointer<<" "<<*pointer<<endl;
    while (*pointer<gtp.size()&&gtp[*pointer] != ',')
        * pointer = *pointer + 1;
    return gtp.substr(start, *pointer - start);
}
string find_next_location(int* pointer,string location)
{
    //    cout<<pointer<<" "<<*pointer<<endl;
    *pointer = *pointer + 1;
    int start = *pointer;
    //    cout<<pointer<<" "<<*pointer<<endl;
    while (*pointer<location.size()&&location[*pointer] != '^')
        * pointer = *pointer + 1;
    return location.substr(start, *pointer - start);
}
void decode_protocol(int out,char fox_protocol[],ofstream &outfile)
{
    string str(fox_protocol);
    outfile<<"野狐传来的字符串: ";
    outfile<<str<<endl;
    outfile<<str.length()<<endl;
    string command;
    string gtp;
    string check;
    string color;
    //加上校验
    int start=0;//一次性输入多组命令时用到，命令的开始
    int index = 0;
    int gtp_start, gtp_end;
    char gtp_format[1024];
    bool command_flag = false;
    bool flag=false;
    while (index < str.size())
    {
        if (str[index] == ',' && !command_flag) {
            outfile<<" command start and end"<<start<<"  "<<index<<endl;
            command = str.substr(start, index-start);
            gtp_start = index;
            command_flag = true;
            cout << "the command is " << command << endl;
        }
        else if (str[index] == '*')
        {
            gtp_end = index;
            gtp = str.substr(gtp_start, gtp_end - gtp_start);
            flag=true;
//            cout << "the gtp string is " << gtp << endl;
        }
        if (str[index] == '<')
        {
            check = str.substr(gtp_end + 1, index - gtp_end - 1);
            break;
        }
        if(str[index]=='\n')
        {
            command_flag=false;
            flag=false;
            start=index+1;
        }
        if(flag) {
            if (command == "$FARULE") {
                sort_FARULE(out, gtp);
            } else if (command == "$FASTATUS") {
                sort_FASTATUS(out, gtp, &color);
            } else if (command == "$FAMOVE") {
                sort_FAMOVE(out, gtp, outfile);
            } else if (command == "$FASKIP") {
                sort_FASKIP(out, gtp);
            } else if (command == "$FARESULT") {
                sort_FARESULT(out, gtp);
            } else if (command == "$FATIMELEFT") {
                sort_FATIMELEFT(out, gtp, color);
            }
            while(index<str.length()&&str[index]!='\n')
                index++;
            continue;
        }
        index++;
    }

    outfile.close();
}
void sort_FASTATUS(int out,string gtp,string* color)
//未知对应的gtp命令 目前理解为告知ai所执棋子的颜色
//$FASTATUS,0*0F
//$FASTATUS,1,B*60
{
    int m = 0;
    string s1 = find_next(&m,gtp);
    if(s1=="0")
        return;
    else
    {
        string s2 = find_next(&m,gtp);
        *color = s2;
        return;
    }
}
void sort_FAMOVE(int out,string gtp,ofstream &outfile)//对应play和genmove
//$FAMOVE,1,B,0^0^0^N*69
{
    int m = 0;
    string is_ai_turn=find_next(&m,gtp);
    if(is_ai_turn=="0")
        return;
    else
    {
        string color = find_next(&m,gtp);
        string op_color;
        if(color=="B")
            op_color="W";
        else
            op_color="B";
        string location = find_next(&m,gtp);
        int index = 0;
        int m = 0;
        string num = find_next_location(&m,location);
        string x = find_next_location(&m,location);
        string y = find_next_location(&m,location);
        int xx = atoi(x.c_str());
        int yy = atoi(y.c_str());
        if(xx>=8)
            xx++;
        x = (char)(xx+65);
        yy=19-yy;
        string play = "play " +op_color + " " + x + to_string(yy);
        cout<<play<<endl;
        write_io(out, play);
        string genmove = "genmove "+color;
        g_color=color;
        outfile<<"FAMOVE: ";
        outfile<<genmove<<endl;
        write_io(out,genmove);

    }
}
void sort_FASKIP(int out,string gtp)
{}
void sort_FARESULT(int out,string gtp)
//$FARESULT,B+350*7D
{

}
void sort_FARULE(int out,string gtp)//$FARULE,19,1200,30,3,650*2D
//1 clear_board
//=1
//
//2 boardsize 19
//=2
//
//3 time_settings 1200 30 1
//=3
//
//4 komi 6.5
//=4
//
//5 time_left B 1200 0
//=5
{
    int i = 1;
    string gtp1 = to_string(i++)+" clear_board";
    write_io(out,gtp1);
    int m = 0;
    string size = find_next(&m,gtp);
    size = to_string(i++)+" boardsize "+size;
    write_io(out,size);
    string time1 = find_next(&m,gtp);
    string time2 = find_next(&m,gtp);
    string time3 = find_next(&m,gtp);
    string time = to_string(i++)+" time_settings "+time1+" "+time2+" "+to_string(1);
    write_io(out,time);
    string komi = find_next(&m,gtp);
    float t = stof(komi)/100;
    string t_string;
    if (t < 7)
        t_string = "6.5";
    else
        t_string = "7.5";
    komi = to_string(i++) + " komi " + t_string;
    write_io(out,komi);
}
void sort_FATIMELEFT(int out,string gtp,string color)
//查看日志发现没有对应的gtp命令，暂不实现???
//$FATIMELEFT,1200,30,3*16
{
    int m=0;
    string s1 = find_next(&m,gtp);
    string str = "time_left "+color+" "+s1+" "+"0";
    write_io(out,str);
}
const char* sort_AFPLAY(char gtp[],ofstream &outfile)//ai传送的gtp格式
//暂时不解决手数问题
{
    char* res;
    string temp;
    outfile<<"receive ai move" << gtp << endl;
    cout << "receive ai move" << gtp << endl;
    temp += "$AFPLAY,";
    temp += "B";
    temp += "1^";
    int x = gtp[2]-65;
    if (x >= 9)
        x--;
    temp += to_string(x);
    temp += "^";
    string s = "";
    for (int i = 3; i <= strlen(gtp); i++)
        s += gtp[i];
    int y = 19-atoi(s.c_str());
    temp += to_string(y);
    temp += "^B*";
    string temp1 = temp.substr(1, temp.length() - 2);
    string use;
    if(!FOXPKG_CalCheckSum(temp1, temp1.length(), use)) {
        cout << "校验出错" << endl;
        return "";
    }
//    FOXPKG_CalCheckSum(temp1, temp1.length(), use);
    temp += use;
    const char* str;
    str = strdup(temp.c_str());
    cout << temp << endl;
    outfile<<temp<<endl;
    //cout << str << endl;
    return str;
}
//int main(int argc, char *argv[])
//{
//     char p[10];
//     for(int i=0;i<5;i++) {
//         p[i] = (char)(i+48);
//         cout<<p[i]<<endl;
//     }

//        cout<<123<<endl;
//        string k = "650";
//        float m = stof(k)/100;
//        cout<<m<<endl;
//}