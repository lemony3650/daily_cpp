#include <iostream>
#include <string> 

using namespace std;

/*********************************************************
 * 抽象数据类型库-标准库
 * string 本身是一个模板类 | c++风格的字符串
 * string 变长字符序列 
-------------------------------------------------------
 * using declaration
 * 1. using namespace lib    as   using namesapce std
 * 2. using namespace::name  as   using std::cin
 *                                using std::string
 * 3. <.h>头文件中不应该包含using声明
*********************************************************/

/************************************************
 * string 对象定义和初始化
 * 直接初始化 
 * 拷贝初始化 = 等号右边的初始值拷贝到新创建的对象中
*************************************************/
void func_demo1()
{
    string s1;              // 默认初始化s1 空串
    string s2 = "abcd";

    // c++11 新特性
    string s3(10,'a');
    string s4("value");

    string s5 = string(10, 'c');    // 创建临时匿名对象

    string str5;
    str5.assign("hello c++");   
}

/*****************************************************************
 *  string类 的具体操作
--------------------------------------
 1. getline(is, str)  遇到换行符结束
 2. str.empty()
 3. str.size()   字符个数 返回无符号整数 不应该与int比较

 4. cout << str
 5. cin >> str   直到遇到空白（空格、换行、制表符）
--------------------------------------------------------------
 * string_lib_function() 
 * string += string         合并
 * == != < <= > =>          字典顺序判断
 -------------------------------------
  1. 字符相同则长度大的字符串比较大
  2. 字符不同则根据首字符依次向下
********************************************************************/
void func_iostr()
{
    // 标准输入读取字符串
    string word;
    while (cin >> word)
        cout << word << endl;

    string line;
    while (getline(cin, line))
        cout << line << endl;
}

void func_demo2()
{
    string s1,s2;
    string s3 = s1 + s2;
    string ss = "hello",sd = "world";
    string s4 = ss + "world" + '!';

    // 错误的叠加方式，两个字面值字符串不能相加
    // string s5 = "hello" + "," + sd;

    // len 的类型是 size_type 是无符号整型，足够容纳字符串的大小
    string str5 = "I";
	str5.append(" love ");
	str5.append("game abcde", 4);
}

/**********************************************
 * string  判断大小写 | 字母
 * cctype头文件
-----------------------------------
 1. isalnum(c)  c是数字或字母时为真
 2. isalpha(c)
 3. isdigit(c)
-----------------------------------
 1. islower(c)
 2. isupper(c)
 ---------------
 1. tolower(c)
 2. toupper(c)
**********************************************/


/*****************************************************
 * 范围for()
 * for (declaration:expression)   逐个的处理每个字符
 *      statement
------------------------------------------------
 * expression 变量，declaration 字符序列
 * 更改可以通过引用方式定义
-----------------------------------
 * decltype()定义str.size()返回的类型
******************************************************/ 
void func_demo3()
{
    string str("somethings");
    decltype(str.size()) count_cnt = 0;

    // 声明引用类型，可以修改原String
    for (auto &c:str){
        c = toupper(c);
        count_cnt++;
    }
}

/*****************************************************
 * 下标运算符[] ||  迭代器使用
 * 逻辑陷阱 && || 
----------------------------------------------
 * 十进制转换成对应的十六进制数，超过15的数字作废
****************************************************/ 
void func_demo3()
{
    const string hexdigits = "0123456789ABCDEF";
    string digit_to_hex;
    size_t num;

    while(cin >> num)
        if(num < hexdigits.size())  // 0-15
            digit_to_hex += hexdigits[num];

    cout << "Hex number: " << digit_to_hex << endl;
}


/*******************************************
 * string insert
 * insert(int pos, const char* str)
 * insert(int pos, int n , char c)
 * erase(int pos, int n = npos)
*******************************************/
