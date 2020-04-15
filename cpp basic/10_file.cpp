#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/***********************************************
 * 1.�ı��ļ� (Ascii��)
 * 2.�������ļ�
 * ofstream | ifstream | fstream
************************************************/

/*********************************************
 * ios::in | ios::out  | ios::ate
 * ios::app| ios::trunc| ios::binary
**********************************************/
void test()
{
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
        cout << "���ļ�ʧ��" << endl;

    // 1.�����ַ������У��Կո�ָ�
    while(ifs >> buf)
        cout << buf << endl;

    // 2.
    while(ifs.getline(buf,sizeof(buf)))
        cout << buf << endl;

    // 3.���������������
    string buff;
    while(getline(ifs,buff))
        cout << buff << endl;

    // 4.���ֽڵĶ�ȡ
    char ch;
    while ((ch = ifs.get())!=EOF)
        cout << ch << endl;
}


int main()
{
    test02();

    return 0;
}
