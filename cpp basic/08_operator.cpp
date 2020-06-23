#include <iostream>
using namespace std;

// operator+
/****************************************************************************
 * 运算符重载，也能发生函数重载
 * 自定义数据类型的运算符运算
 * 1. 可以自己实现相加操作，例如设计一个成员函数 Person func(const Person& p)
 * 2. 编译器实现一个通用的方法,操作自己定义 （成员函数 | 全局函数 重载）
      Person p3 = Person p1.operator+(p2) 
      Person p3 = p1 + p2    (简化版本)
   3. 编译器会自动构造赋值运算符，浅拷贝
******************************************************************************/
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
    
    // 成员函数重载++  区分++i  i++  即返回的是本身还是提前记录一个tmp
    // 1. 前置
    Person& operator++()
    {
        m_A++;
        m_B++;
        return *this;
    }
    // 2. 后置  int占位
    Person& operator++(int)
    {
        Person tmp = *this;
        m_A++;
        return tmp;
    }


    // 成员函数重载=
    Person& operator=(Person &p)
    {
        // 判断是否有堆区内存占有，有的话先释放掉
        if(m_C != NULL) {
            delete m_C;
            m_C = NULL;
        }

        m_C = new int(*p.m_C);

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
    // 函数调用运算符重载()
    void operator()(string name)
    {
        cout << name << endl;
    }

    int m_A;
    int m_B;
    int *m_C;
};

// 全局函数实现重载+， 运算符的重载也可以发生函数重载
Person operator+(Person &p1,Person &p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;

    return temp;
}

/********************************************************
 * 全局函数作左移运算符重载, 成员函数不行,访问类内可以用友元
 *  1. 成员函数的话会出现两个对象
 *  2. 写成cout 在进行简化时 p << cout  不行
 * 输出自定义类型的<< 
 * 返回值类型的引用 能够保证可以继续输出
*********************************************************/
ostream& operator<<(ostream &cout,Person &p)
{
    // operator(cout,p)   ==  cout << p
    cout << p.m_A << " " << p.m_B << endl;
    return cout;
}

void test01()
{
    Person p1 = {1,2};
    Person p2 = {3,4};

    // Person p3 = p1.operator+(p2) 本质 两者都可以
    Person p3 = p1 + p2;

    cout << p3.m_A << " " << p3.m_B << endl;

    p1("jerry");     // 仿函数 p1是对象，不是函数

}

int main()
{
    test01();

    system("pause");
    return 0;
}