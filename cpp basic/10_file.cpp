#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/***********************************************
 * 1.文本文件 (Ascii码)
 * 2.二进制文件
 * ofstream | ifstream | fstream 三种文件流
 * 写          读          读写
************************************************/

/********************************************************
 * ios::in | ios::out                  | ios::ate 文件尾
 * ios::app| ios::trunc 先删除再创建新的 | ios::binary
*********************************************************/
void test01()
{
    // 创建流对象 写
    ofstream ofs;

    ofs.open("filename.txt",ios::out);

    ofs << "write data to ofs" << endl;

    ofs.close();

}

void test02()
{
    ifstream ifs;

    char buf[1024] = {0};
    
    ifs.open("filename.txt",ios::in);

    if (!ifs.is_open())
        cout << "打开文件失败" << endl;

    // 1.读到字符数组中，以换行分隔
    while(ifs >> buf)
        cout << buf << endl;

    // 2.getline   arg1: *buf   arg2: size
    while(ifs.getline(buf,sizeof(buf)))
        cout << buf << endl;

    // 3.从输出读到输入流
    // 全局getline函数
    string buff;
    while(getline(ifs,buff))
        cout << buff << endl;

    // 4.单字节的读取
    char ch;
    while ((ch = ifs.get())!=EOF)
        cout << ch << endl;

    ifs.close();
}


int main()
{
    test02();

    return 0;
}
