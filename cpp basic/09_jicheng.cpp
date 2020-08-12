#include <iostream>
using namespace std;

/****************************************************************************
 * 继承 
 * class 子类 : 继承方式 父类1,继承方式 父类2
 * 继承方式指的派生类对基类的访问权限，
 * 1.公有 2.保护 3.私有
 * 公有继承： 1.公有 2.保护 3.私有   派生类只能访问基类的公有和保护
 * 保护继承： 1.保护 2.保护 3.私有   派生类只能访问基类的保护
 * 私有继承： 1.私有 2.私有 3.私有   派生类对基类都不能访问
 * 而派生类内的属性代表派生类对象的访问权限
--------------------------------------------------------------
 * 派生类继承基类，对于私有成员还是存在的，只是不能访问，被隐藏起来
 * 即派生类保留基类所有非静态成员，内存照样开辟
 ---------------------------------------------
 * 基类和派生类的构造和析构，对于派生类（依赖基类）
 *  1.先有基类的构造 再有派生类构造
 *  2.现有派生类析构，再有基类析构
*****************************************************************************/
class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class son1 : public Base
{
public:
    void func()
    {
        m_A = 10;  
        m_B = 20;
        // m_C 派生类访问不到基类私有
    }
    // 同时派生类类外访问不到m_B 
};

class son2 : protected Base
{
public:
    void func()
    {
        m_A = 10;
        m_B = 20;
        // m_C 派生类访问不到基类私有
    }
    // 同时派生类类外访问不到任何
};

class son3 : protected Base
{
public:
    void func()
    {
        //派生类访问不到基类私有
    }
    // 同时派生类类外访问不到任何
};

/*****************************************************************
 * 虚继承和虚基类 - 菱形继承关系
   对于从同一个父类继承来的两个子类，而通过两个子类共同继承来的子子类
   1. 可以通过作用域进行区分识别
   2. 但一般通常只需要一份内存，如何解决这个问题
 * 通过virtual 虚继承的方式，变量在内存中只保留一份,即有个vbptr指针
   而父类则成为虚基类
*******************************************************************/
class animal
{
public:
    int a_Age;
};
class sheep:virtual public animal{};
class tuo:virtual public animal{};
class sheeptuo:public sheep, public tuo{};

void test02()
{
    sheeptuo s;
    s.sheep::a_Age = 10;
    s.tuo::a_Age = 20;
    s.a_Age = 30;

    // vbptr 虚基类指针  ->  指向vbtable  -> a_Age
}

/**********************************************************************
 * 多态，能够满足开闭原则，组织结构清晰，可读性强，可扩展维护
 * 1.静态多态： 函数重载、运算符重载
 * 2.动态多态： 派生类和基类实现动态绑定
 *   virtual 虚函数实现在运行时动态绑定的过程，因此派生类要重写虚函数
 *   通过函数传入基类形参
***********************************************************************/
class Animal 
{
    public:
        // 虚函数
        virtual void speak(){ cout << "animal is speaking..." << endl;}
};

class Cat:public Animal
{
    public:
        // Virtual 可加可不加
        virtual void speak(){cout << "cat is speaking..." << endl;}
};
/*******************************************************
 * Animal tmp = Cat p  子类可以初始化父类，进行类型转换
 * 但若不是虚函数，会地址早绑定，在编译阶段进行地址绑定了
 * 需要虚函数使得地址晚绑定
*******************************************************/
void doSpeak(Animal &p)
{
    p.speak();
}

/*************************************************************************
 * 多态本质
 * 1. 空类占一个字节
 * 2. 同一个类的不同实例共享一个虚函数表(编译时产生)
      而每个类内有一个指向一个指针数组(虚函数表)的指针vfptr
 *   虚函数基类内部
      1. 存在一个指针vfptr -> vftable &Animal::speak  (占四个字节)
 *   派生类内部 
      1. 首先完全继承基类的成员属性，包括指向基类虚函数表的指针vfptr
      2. 当发生重写时，指针vfptr 便指向了派生类内部的函数  -> vftable &Cat::speak
      3. 当派生类也创建虚函数时，会在基类虚函数表后面添加，因此sizeof()不变
      4. 当发生多继承时，按顺序创建虚函数表及多个vfptr
--------------------------------------------------------------------------
 * 纯虚函数，即存在至少一个纯虚函数的类，称为抽象类（无法实例化对象）, 无函数体
  1. 一般由于基类的虚函数没有用，用不到，因此写成纯虚函数
  2. virtual void func() = 0;
  3. 子类必须重写父类虚函数
*************************************************************************/
class Calculate
{
public:
    virtual int getresult()
    {
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

class AddCalculate:public Calculate
{
    int getresult()
    {
        return m_Num1 + m_Num2;
    }
};

void test02()
{
    Calculate *abc = new AddCalculate;
    abc->m_Num1 = 1;
    abc->m_Num2 = 2;
    abc->getresult();
    delete abc;
}
/*****************************************************************
 * 虚析构 | 纯虚析构
 * 在通过动态多态时，父类指针指向了子类对象，而父类指针销毁时是不会调用子类的析构函数
   因此通过父类的虚析构，来解决子类析构的堆区内存释放
   虚析构必须要有定义和声明，即子类也要实现对应的析构方式
 * 纯虚析构必须在基类中也有具体实现
******************************************************************/

/****************************************************************
公有继承的方式中
    通过在基类声明虚函数，表明希望派生类进行覆盖
    在派生类中添加关键字 override 声明改写自己的虚函数
    以防止在派生类中由于参数列表的不同产生一个新的函数，而虚函数却没覆盖掉
    final 表示不允许被覆盖，即不能再被继承
------------------------------------------------------------------
 * 根据传入的item对象不同，而调用不同的虚函数，实现动态绑定
 * 根据形参决定运行的版本，即在运行时选择函数版本，动态绑定又称运行时绑定
*****************************************************************/
class Quote {
public:
    string isbn() const;
    // 除构造函数外的非静态函数都可以是虚函数

    // virtual 只能出现在类内部声明，而不能出现在外部定义
    virtual double net_price(size_t n) const;
};

class Bulk_quote:public Quote {
public:
    double net_price(size_t n) const override; 
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " <<  item.isbn()  << " # sold: " 
            << n << "total due: " << ret << endl;

    return ret;
}

/******************************************************************
 * 通过公有继承
    派生类能够向基类进行隐式的类型转换，是由于派生类对象中含有与基类对应的部分
    而不存在基类转向派生类的方式
    当派生类初始化基类时只会初始化共同存在的部分，派生类其余部分则会被砍掉
-------------------------
完善定义Quote基类
*******************************************************************/
class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
        bookNo(book),price(sales_price){}

    string isbn() const {return bookNo;};
    virtual double net_price(size_t n) const
                            {return n * price;};

    // 虚析构函数
    virtual ~Quote() = default;

    //基类中的静态成员无论派生出多少个，都是唯一存在的一个实例对象
    //遵循访问控制
    static int flag;
private:
    string bookNo;
protected:
    double price = 0.0;
};

// 完善派生类
class Bulk_quote:public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc):
                Quote(book,p),min_qty(qty),discount(discount){};

    // 派生类成员自己的成员函数实现       
    double net_price(size_t cnt) const override
    {
        if(cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else 
            return cnt * price;
    };
    // public继承 还存在基类的函数和成员

    //using 可以改变类中的访问控制
    using Quote::price;
private:
    size_t min_qty = 0;                 // 满足折扣的最小购买量
    double discount = 0.0;              // 折扣额
};


/**********************************************************************
 * 一个类既可以是基类，也可以是派生类，即通过基类继承得到D1，而D2又通过D1继承而来
   因此为防止不需要的继承，可以声明关键字 final
***********************************************************************/
class NoDervived final{};

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
        bookNo(book),price(sales_price){}

    string isbn() const {return bookNo;};
    virtual double net_price(size_t n) const
                            {return n * price;};
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

/****************************************************************
 * 一般是通过重构的方式添加派生类对象
    即只保存购买量和折扣值，具体打折措施由派生类去做
    不能直接定义Disc_quote对象，必须通过派生并覆盖net_price方式实现
*****************************************************************/
class Disc_quote:public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price,size_t qty,double disc):
        Quote(book,price),quantity(qty),discount(disc){}

    // 纯虚函数，无实际意义，限制用户使用类
    double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};
/*******************************************************
 * 通过直接基类 Disc_quote 派生出 Bulk_quote，间接基类Quote
*******************************************************/
class Bulk_quote:public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc):
                Disc_quote(book,p,qty,discount){};
    double net_price(size_t) const override;
};