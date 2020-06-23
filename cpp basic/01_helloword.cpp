#include <iostream>
#include <string>
using namespace std;

/******************************************
 * 常量
 * 宏常量 | 字符串常量
 * const 修饰的常量(全局|局部)
*******************************************/
#define Num 10
const int Number = 10;

/**************************************************
 * 数据类型占用长度
 * sizeof(value || datatype)
 * char-1  char存放以ascii码的二进制进行存放
 * cpp 可以cout 直接输出字符串  cin 可以直接输入字符串
 * short-2  int-4   long-4  
 * float-4  double-8  bool-1
****************************************************/
void test01()
{
    char a = 'a';
    //c风格字符串
    char str[] = "hello world";
    //cpp风格
    string str1 = "hello world cpp";

    cout << int(a) << endl;
    cout << str << endl;
}

/**************************************************
 * float-4(精度 7有效数字)  double-8(精度15-16)
 * 浮点数默认双精度，添加f
 * 默认输出小数只有六位有效数字，额外需要添加
 * 科学表示法e 
**************************************************/
void test02()
{
    float f1 = 3.1415926f;
    cout << f1 << endl;

    system("pause");
}


/**********************************************************************
 * 内存分区
 * 代码段 | 数据段 | 栈 | 堆
 * 代码段：二进制可执行文件，共享|只读
 * 数据段：全局变量 | 静态（全局|局部）变量 | 常量  （字符串 | const全局常量）
 * 栈： 局部变量 | const局部变量 | 函数参数， 不要返回局部变量的地址
 * 堆： 主动申请释放
************************************************************************/
int g_a = 10;
static int a = 20;  
const int b = 30;
void test03(int m)
{
    static int c = 40;
    int d = 50;
    const int e = 60;

    m = 70;

    // 利用new delete 申请释放内存
    int *p = new int(80);
    int *arr = new int[10];

    cout << g_a << " " <<(int)&g_a << endl;
    cout << a << " " <<(int)&a << endl;
    cout << b << " " <<(int)&b << endl;
    cout << c << " " <<(int)&c << endl;
    cout << d << " " <<(int)&d << endl;
    cout << e << " " <<(int)&e << endl;

    cout << m << " " <<(int)&m << endl;
    cout << *p << " " << (int)p << endl;

    delete p;
    delete[] arr;
}


/***********************************************
 * 转义字符
 * \\反斜杠输出   \'  \"    \?    \0  
 * \t制表符   \n换行   \ddd   \xhh
 * 三目运算符,可以返回变量 
 * (表达式1？表达式2：表达式3) = x 
************************************************/

/*******************************************
 * if if-else if-else if
 * while 先判断 ->  执行{}  -> 判断
 * do{}while(条件)   先执行{} -> 判断 
 * for(起始表达；条件表达；末尾循环体)
 * 1.起始 2.条件 3.{} 4.末尾 5. 条件 
 * continue   break
 * goto 标记符；
*******************************************/

/******************************************* 
 * 水仙花数 ge^3 + shi^3 + bai^3 == num
********************************************/
void test04()
{
    int num = 100;
    int ge = 0;
    int shi = 0;
    int bai = 0;

    while(num <= 999) {

        ge = num % 10;
        shi = num / 10 % 10;
        bai = num /100;

        if((ge*ge*ge + shi*shi*shi + bai*bai*bai) == num)        
            cout << num << endl;

        num++;
    } 
}
/**********************************************************
 * 乘法口诀表
**********************************************************/
void test05()
{
    int i,j;

    for(i = 1;i <=9; i++){
        for(j = 1; j <= i; j++)
            cout << j << "*" << i << "=" << i*j << "   ";

    cout << endl;
    }
}



int main()
{
    test03(0);

    system("pause");
    return 0;
}