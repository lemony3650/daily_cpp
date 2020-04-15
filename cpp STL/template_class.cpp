#include <iostream>
#include <string>
using namespace std;

/********************************************************************
 * 类模板，建立一个通用类对象 + 类
 * template<typename T>
 * class 
 * 类模板无法自动进行推导，必须指定类型，但类模板可以有默认参数类型
 * 类外实现的成员函数需要添加模板参数列表
********************************************************************/
template<typename NameType, typename AgeType = int>
class Person
{
    public:
        Person(NameType name, AgeType age);

        void showPerson();

        NameType mName;
        AgeType  mAge;
};

//构造函数 类外实现
template<typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

//成员函数 类外实现
template<typename T1, typename T2>
void Person<T1, T2>::showPerson() {
	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}

void test01()
{
    // 必须指定Person<>类型
    Person<string, int> p1("yourname",666);
    p1.showPerson();

    Person<string> p2("yourname",1);
    p2.showPerson();
}

/***********************************************
 * 类模板中成员函数只有在函数调用时才会创建
 * 如新建两个类，通过第三个模板类进行调用
************************************************/
class Person1
{
    public:
        void showPerson1()
        {
            cout << "Person1 show" << endl;
        }
};

class Person2
{
    public:
        void showPerson2()
        {
            cout << "Person2 show" << endl;
        }
};

template<typename T>
class MyClass
{
    public:
        T obj;

        void func_1(){obj.showPerson1();};
        void func_2(){obj.showPerson2();};
};

void test02()
{
    MyClass<Person1> m;

    m.func_1();

    // 能够进行调用，但在调用时并没有此方法
    // 因此函数调用时才会创建成员函数
    // m.func_2();
}

/*****************************************************************
 * 类模板对象作为函数的参数实现，一般会选择第一种方式
 * 1.指定参数实例
 * 2.类模板参数,指定参数类型为模板 template<typename T1, typename T2>
 * 3.整个类模板化 template<typename T>
********************************************************************/
void printPerson1(Person<string,int> &p);

template<typename T1, typename T2>
void printPerson2(Person<T1,T2> &P);

template<typename T>
void printPerson3(T &p);

/********************************************************
 * 子类继承父类（类模板）时需要指定父类的参数类型T
 * 必须指定，否则无法分配内存
 * 若需要灵活指定父类T的参数类型，子类也需变为模板类
*********************************************************/
template<typename T>
class Base
{
    T m;
};
// 父类必须指定类型
class Son:public Base<int>
{

};
// 模板子类继承模板父类
template<typename T1, typename T2>
class Son_1:public Base<T2>
{
    public:
        Son_1()
        {
            cout << typeid(T1).name << end;
            cout << typeid(T2).name << end;
        }
};

Son_1<int,char> child;

/*****************************************
 * 分文件编写的.c/.h文件在连接的时候
 * 1.在源文件中需要包含.cpp源文件
 * 2.声明和实现写在一个文件中，称.hpp文件
*****************************************/

/***************************************************************************
 * 类模板与友元函数的实现
 * 1.类内实现
 * 2.类外实现
****************************************************************************/
//2、全局函数配合友元  类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
template<class T1, class T2> class Person;

//如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
//template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 

template<class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
	cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//1、全局函数配合友元   类内实现
	friend void printPerson(Person<T1, T2> & p)
	{
		cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
	}

	//全局函数配合友元  类外实现
	friend void printPerson2<>(Person<T1, T2> & p);

    public:
        Person(T1 name, T2 age)
        {
            this->m_Name = name;
            this->m_Age = age;
        }

    private:
        T1 m_Name;
        T2 m_Age;
};

//1、全局函数在类内实现
void test01()
{
	Person <string, int >p("Tom", 20);
	printPerson(p);
}

//2、全局函数在类外实现
void test02()
{
	Person <string, int >p("Jerry", 30);
	printPerson2(p);
}
