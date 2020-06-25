#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/***********************************************
 * 1.�ı��ļ� (Ascii��)
 * 2.�������ļ�
 * ofstream | ifstream | fstream �����ļ���
 * д          ��          ��д
************************************************/

/********************************************************
 * ios::in | ios::out                  | ios::ate �ļ�β
 * ios::app| ios::trunc ��ɾ���ٴ����µ� | ios::binary
*********************************************************/
void test01()
{
    // ���������� д
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

    // 1.�����ַ������У��Ի��зָ�
    while(ifs >> buf)
        cout << buf << endl;

    // 2.getline   arg1: *buf   arg2: size
    while(ifs.getline(buf,sizeof(buf)))
        cout << buf << endl;

    // 3.���������������
    // ȫ��getline����
    string buff;
    while(getline(ifs,buff))
        cout << buff << endl;

    // 4.���ֽڵĶ�ȡ
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
