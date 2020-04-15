#include <iostream>
using namespace std;

// operator+

/*************************************************
 * 运算符重载
 * 自定义数据类型的运算符运算
 * 1.本可以自己实现相加操作，编译器实现一个通用的方法
 * 2.操作自己定义
**************************************************/
class Person
{
    public:

        // 成员函数重载+
        Person operator+(Person &p)
        {
            Person tmp;
            tmp.m_A = this->m_A + p.m_A;
            tmp.m_B = this->m_B + p.m_B;
            return tmp;
        }
        
        // 成员函数重载++ 
        // 区分++i  i++  即返回的是本身还是提前记录一个tmp
        Person& operator++()
        {
            m_A++;
            m_B++;
            return *this;
        }

        // 成员函数重载=
        Person & operator=(Person &p)
        {
            if(m_C != NULL)
                delete m_C;

            m_C = new int (*p.m_C);

            return *this;
        }   

        //比较运算发重载==
        bool operator==(Person &p)
        {
            if ( this->m_A == p.m_A && this->m_B == p.m_B )
                return true;
            else 
                return false;
        }

        // 仿函数()
        void operator()(string name)
        {
            cout << name << endl;
        }

        int m_A;
        int m_B;
        int *m_C;
};

// 全局函数实现重载+， 运算符的重载也可以发生函数重载
/*
Person operator+(Person &p1,Person &p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;

    return temp;
}
*/

int main()
{
    Person p1 = {1,2};
    Person p2 = {3,4};

    // Person p3 = p1.operator+(p2)
    Person p3 = p1 + p2;

    cout << p3.m_A << " " << p3.m_B << endl;

    p1("jerry");     // 仿函数 对象()

}

/***********************************************
 * 全局函数 左移运算符重载,左移运算符重载
 * 输出自定义类型的<< 
 * 返回值类型保证可以继续输出
************************************************/
ostream& operator<<(ostream &cout,Person &p)
{
    cout << p.m_A << " " << p.m_B << endl;
    return cout;
}