#include <iostream>
#include <string>
using namespace std;

/**********************************************************
 * 抽象、封装、继承、多态
 * 1.属性|行为 (权限控制，默认是私有权限)
 *   public     类内可以访问  类外也可以访问
 *   protected               类外不能访问
 *   private                 类外不能访问
-----------------------------------------------------------
 * cpp中的成员变量和成员函数分开存储
 * 静态成员变量不属于类对象上的，只有非静态成员变量才属于
 * 每个非静态成员函数只有一份实例，通过this指针，也不属于类对象哩的
 * --------------------------------------
 * 1. 空类占的内存空间 1byte
************************************************************/
class Person 
{
public:
    string name;
protected:
    string car;
private:
    string passwd;

public:
    //类内都可以访问
    void show()
    {
        name = "zhangsan";
        car = "123";
        passwd = "456";
    }
};

void test01()
{
    Person p1;
    //类外 只能访问到公有
    p1.name = "lisi";
}
/************************************************************
 * 初始化和清理
 * 构造和析构，不写时编译类型默认产生一个空的函数体，由编译器自动调用
 * 没有函数返回值，也没有void
   1. 构造函数可以有参数，因此可以重载
   2. 析构没有参数，因此不能重载
**************************************************************/
class Student 
{
public:
    // 构造函数
    Student(){cout << 1 << endl;}   //类内定义
    Student(string name,int id):mName(name),mId(id){}
    // 析构函数
    ~Student(){cout << 2 << endl;}

    void showStudent(); //; 函数声明

// 类内可以访问，类外不能访问，继承中体现出protected
protected:  
// 类内可以访问，类外不能访问
private:
    string mName;
    int    mId;
};

// 类外定义成员函数
void Student::showStudent()
{

}
/***************************************************************************
 * 构造函数区分： 普通构造 |  拷贝构造            默认构造 |  有参构造
 * 拷贝构造函数,参数类型为 Person(const Person &p)
 * 构造函数的调用
   1.括号法  2. 显示法  3. 隐士转换
----------------------------------------------------------------------
 * 1.默认构造函数调用时不要加(),此时编译器会认为是一个函数声明
 * 2.匿名对象 Person(10) 运行后会立即回收，不要用拷贝构造函数初始化匿名对象
*****************************************************************************/
class Studentt 
{
public:
    // 默认构造函数, 实际使用时不能为空
    Studentt();

    // 有参构造
    Studentt(int a);

    //拷贝构造
    Studentt(const Studentt& s1)
    {
        mName = s1.mName;
        mId = s1.mId;  
    }

    // 析构函数
    ~Studentt();

private:
    string mName;
    int    mId;
};

void test02()
{
    // 会自动调用构造和析构函数
    Student s;

    //括号法
    Studentt s1;     //默认构造时不要用Studentt s1();
    Studentt s2(10);
    Studentt s3(s2);

    //显示法           =右边  匿名对象
    Studentt s4;
    Studentt s5 = Studentt(10);
    Studentt s6 = Studentt(s5);

    // 隐士转换法
    Studentt p = 10;
}
/*************************************************
 * 拷贝构造函数的应用
 * 1.通过已有的类型参数初始化一个新的对象中
 * 2.参数进行值传递的时候调用拷贝构造函数
 * 3.返回值传递方式调用拷贝构造函数
**************************************************/

/************************************************
 * 三种构造函数的调用规则
 * 1.提供拷贝构造函数，则系统不会再提供其他两种
 * 2.提供有参构造，则系统不会再提供默认
 ----------------------------------------------
 * 嵌套的类对象的构造和析构顺序
 * 1. 外类依赖嵌套类，因此构造是从里到外，先构造类内的嵌套类对象
 * 2. 析构则与之相反
************************************************/

/**************************************************************
 * 当没有自定义拷贝构造函数时，编译器会自动生成，带来浅拷贝（赋值）
 *  1. 浅拷贝：简单的赋值拷贝操作，带来堆区内存重复释放
 *  2. 深拷贝：在堆区重新申请空间，进行拷贝操作
 * 在堆区开辟到的内存，通过浅拷贝而两个对象指向了同一个堆区
 * 因此释放时会重复释放，故设置拷贝构造函数，开辟一个新空间去接收
**************************************************************/
class teacher
{
public:
    teacher(string name, int number)
    {
        n_Name = name;
        h_height = new int(number);
    }

    // 深拷贝 
    teacher(const teacher& t)
    {
        n_Name = t.n_Name;
        h_height = new int(*t.h_height);
    }
    ~teacher()
    {
        if(h_height != NULL) {
            delete h_height;
            h_height = NULL;
        }
    }

private:
    string n_Name;
    int *h_height;
};

void test03()
{
    teacher t1("zhangsan",160);
    teacher t2(t1);

}
/*********************************************************************
 * static 静态成员与成员函数
 * 在编译阶段进行分配，类内声明，类外定义，所有对象共享同一份内存
**********************************************************************/
class person1
{	
public:
	static int m_A; //静态成员变量
private:
	static int m_B; //静态成员变量也是有访问权限的
};

int Person::m_A = 10;
int Person::m_B = 10;

void test04()
{
	//静态成员变量两种访问方式
	//1、通过对象
	Person p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
	cout << "p2.m_A = " << p2.m_A << endl;

	//2、通过类名
	cout << "m_A = " << Person::m_A << endl;
	//cout << "m_B = " << Person::m_B << endl; //私有权限访问不到
}

/*********************************************************************
 * 1.成员函数可以通过对象、也可以通过类名访问，也有访问权限限制
     只能访问静态成员变量，而不能访问非静态
 * 2.成员变量在类内声明，类外初始化,程序共享一个函数
**********************************************************************/
class Person2
{
public:
	static void func()
	{
		cout << "func调用" << endl;
		m_A = 100;
		//m_B = 100; //错误，不可以访问非静态成员变量
	}

	static int m_A; //静态成员变量
	int m_B; // 

private:
	//静态成员函数也是有访问权限的
	static void func2()
	{
		cout << "func2调用" << endl;
	}
};
int Person::m_A = 10;

void test05()
{
	//静态成员变量两种访问方式
	//1、通过对象
	Person p1;
	p1.func();

	//2、通过类名
	Person::func();
	//Person::func2(); //私有权限访问不到
}
/*****************************************************
 * this指针指向被调用成员函数所属于的对象
 * this指针隐含在每一个非静态成员函数里面，不需要定义，直接使用
 * 1. 区分形参和成员变量
 * 2. 返回对象本身*this
 * 3. 空指针调用成员函数，在不使用参数时则是允许的,当为空时this为空
      无法指向
*******************************************************/


/****************************************************************
 * const 成员函数 ->  常函数
            不能修改成员属性，但可以加mutable修改
   Person * const this   即this是常量指针，指向无法更改
   const Person * const this  == void func() const
 * const 成员对象  -> 常对象
   常对象只能调用常函数
   const Person p
*******************************************************************/
int main()
{
    test03();

    system("pause");
    return 0;
}