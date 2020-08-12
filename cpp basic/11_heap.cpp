#include <iostream>
#include <string>

#include <memory>       // 智能指针头文件

using namespace std;

/****************************************************************
 * 智能指针（两种，底层实现不一样）
-------------------------------------
 * 1.内存泄漏 没有及时释放内存
 * 2.非法访问 错误释放内存
-------------------------------------
 * 模板类需指出对象类型，内部实现计数器，自动释放内存，调用析构函数
 * shared_ptr
 * unique_ptr
---------------------------------------------------------
 * weak_ptr  伴随类，是一种弱引用，指向shared_ptr所管理的对象
----------------
 * make_shared<>
******************************************************************/
void test01()
{
    // 1. 调用make_shared 在动态内存中分配一个对象并初始化
    shared_ptr<int> p1    = make_shared<int>(42);
    shared_ptr<string> p2 = make_shared<string>("hello world");

    shared_ptr<int> p3 = make_shared<int>();
    shared_ptr<string> p5(p2);

    // 2. 可以使用auto
    auto p4 = make_shared<int>(10);

    // 3. 直接初始化 shared_ptr new 结合使用
    shared_ptr<int> p6(new int(10));

    swap(p1, p4);
    p1.swap(p4);
    p1.unique();            // 是否只有一个引用 bool型
    p1.use_count();         // 返回智能指针计数

    cout << *p1 << endl;
}

/**********************************************
 * new | delete
--------------------------------
 * 在自由空间分配内存是无名的，无法分配对象命名
 * 返回一个指向该对象的指针
***********************************************/
void test02()
{
    int *p1 = new int(10);
    string *p2 = new string(10,'c');

    string *str1 = new string;              // 默认初始化为空
    string *str2 = new string();            // 值初始化为空

    delete p1;
    // delete p1[];

    p1 = nullptr;
}


/*******************************************
 * unique_ptr
 * 只能通过绑定new来初始化一个唯一智能指针
 * 不能进行拷贝构造 p(q)
*******************************************/
void test03()
{
    unique_ptr<int> p1(new int(42));

    p1.release();            // 释放置空    能够用来初始化另一个智能指针

    unique_ptr<int> p2 (p1.release());
}

/***********************************************************************
 * weak_ptr
 * 指向一个shared_ptr管理的对象，绑定之后不会改变shared_ptr计数
 * 当对象计数为0释放时，即使有weak_ptr 也会被释放
 * 当两个对象相互引用时会关联，无法释放，通过伴随类，弱引用可以处理
***********************************************************************/
void test04()
{
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);        // wp弱引用p

    // 对象可能不存在，因此通过lock()
    if (shared_ptr<int> np = wp.lock()) {   // 存在则返回一个shared_ptr
        // np 与 p 共享对象
    }
}

int main()
{
    test01();

    return 0;
}