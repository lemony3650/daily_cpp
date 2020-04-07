#include <iostream>
using namespace std;

/******************************************
 * string c++�ַ���
 * string ������һ����
******************************************/

/***************************************************
 * using declaration
 * 1.using namespace lib    as   using namesapce std
 * 2.using namespace::name  as   using std::cin
 * 3.<.h>file ��Ӧ�ð���using����
****************************************************/

/*********************************************
 * string �䳤�ַ�����using std::string
 * ֱ�ӳ�ʼ�� =
 * ������ʼ��
**********************************************/
void func_demo1()
{
    string s1;              // Ĭ�ϳ�ʼ��s1 �մ�
    string s2 = "abcd";
    // c++11 ������
    string s3(10,'a');
    string s4("value");

    string str5;
    str5.assign("hello c++");   
}

/*************************************************
 * string_lib_function() 
 * string += string         �ϲ�
 * == != < <= > =>          �ж�
**************************************************/
void func_demo2()
{
    string s1,s2;
    string s3 = s1 + s2;
    string ss = "hello",sd = "world";
    string s4 = ss + "world" + '!';
    // ����ĵ��ӷ�ʽ������ֵ�ַ����������
    // string s5 = "hello" + "," + sd;

    // len �������� size_type ���޷������ͣ��㹻�����ַ����Ĵ�С

    string str5 = "I";
	str5.append(" love ");
	str5.append("game abcde", 4);

    s1.empty();
    auto len = s1.size();

    cin >> s1;
    getline(cin,s1);            // \n��������
    cout << s1 << endl;
}

/**************************************************
 * string �Ƚϲ�ȡ�ֵ���ʽ����
 * �ַ���ͬ�򳤶ȴ���ַ����Ƚϴ�
 * �ַ���ͬ��������ַ���������
***************************************************/ 

/*****************************************************
 * for (declaration:expression)   ����Ĵ���ÿ���ַ�
 *      statement
 * expression ������һ���ַ����У�declaration ����
 * decltype()����str.size()���ص�����
******************************************************/ 
void func_demo3()
{
    string str("somethings");
    decltype(str.size())count_cnt = 0;

    // �����������ͣ������޸�ԭString
    for (auto &c:str){
        c = toupper(c);
        count_cnt++;
    }
}
/*****************************************************
 * �±������[]
 * �߼����� && || 
 * ʮ����ת���ɶ�Ӧ��ʮ��������������15����������
****************************************************/ 
const string hexdigits = "0123456789ABCDEF";
string digit_to_hex;
size_t num;
void func_demo3()
{
    while(cin >> num)
        if(num < hexdigits.size())
            digit_to_hex += hexdigits[num];

    cout << "Your hex number is: " << digit_to_hex << endl;
}
/*******************************************
 * string insert
 * insert(int pos,const char* str)
 * insert(int pos,int n ,char c)
 * erase(int pos,int n=npos)
*******************************************/