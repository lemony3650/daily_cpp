#include <iostream>
using namespace std;

/******************************************
 * string c++字符串
 * string 本身是一个类
******************************************/

/***************************************************
 * using declaration
 * 1.using namespace lib    as   using namesapce std
 * 2.using namespace::name  as   using std::cin
 * 3.<.h>file 不应该包含using声明
****************************************************/

/*********************************************
 * string 变长字符序列using std::string
 * 直接初始化 =
 * 拷贝初始化
**********************************************/
void func_demo1()
{
    string s1;              // 默认初始化s1 空串
    string s2 = "abcd";
    // c++11 新特性
    string s3(10,'a');
    string s4("value");

    string str5;
    str5.assign("hello c++");   
}

/*************************************************
 * string_lib_function() 
 * string += string         合并
 * == != < <= > =>          判断
**************************************************/
void func_demo2()
{
    string s1,s2;
    string s3 = s1 + s2;
    string ss = "hello",sd = "world";
    string s4 = ss + "world" + '!';
    // 错误的叠加方式，字面值字符串不能相加
    // string s5 = "hello" + "," + sd;

    // len 的类型是 size_type 是无符号整型，足够容纳字符串的大小

    string str5 = "I";
	str5.append(" love ");
	str5.append("game abcde", 4);

    s1.empty();
    auto len = s1.size();

    cin >> s1;
    getline(cin,s1);            // \n结束本行
    cout << s1 << endl;
}

/**************************************************
 * string 比较采取字典形式方法
 * 字符相同则长度大的字符串比较大
 * 字符不同则根据首字符依次向下
***************************************************/ 

/*****************************************************
 * for (declaration:expression)   逐个的处理每个字符
 *      statement
 * expression 对象是一个字符序列，declaration 变量
 * decltype()定义str.size()返回的类型
******************************************************/ 
void func_demo3()
{
    string str("somethings");
    decltype(str.size())count_cnt = 0;

    // 声明引用类型，可以修改原String
    for (auto &c:str){
        c = toupper(c);
        count_cnt++;
    }
}
/*****************************************************
 * 下标运算符[]
 * 逻辑陷阱 && || 
 * 十进制转换成对应的十六进制数，超过15的数字作废
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