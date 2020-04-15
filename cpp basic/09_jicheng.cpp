#include <iostream>
using namespace std;

/************************************************************
 * 继承 class 子类 : 继承方式 父类1,继承方式 父类2,继承方式 父类3
 * public    派生类能够直接访问，外部也能访问
 * protected 派生类能够直接访问，而外部函数则不能访问
 * private   只能被基类内部访问，外部也不能访问
*************************************************************/

/***************************************************************************
 * 继承方式指的派生类对基类的访问权限，而派生类内的属性代表派生类对象的访问权限
 * 1.公有 2.保护 3.私有
 * 公有继承 1.公有 2.保护 3.私有
 * 保护继承 1.保护 2.保护 3.私有
 * 私有继承 1.私有 2.私有 3.私有
*****************************************************************************/

/******************************************************************
 * 派生类继承基类的时候，对于私有成员，还是存在的，只是不能访问被隐藏起来
 * 即派生类保留基类所有非静态成员，内存开辟
 * 基类和派生类的构造和析构，对于派生类
 * 1.先有基类的构造 再有派生类构造
 * 2.现有派生类析构，再有基类析构
 ******************************************************************/


/*****************************************************************
 * 虚继承和虚基类 - 菱形继承关系
 * 对于从同一个父类继承来的两个子类，而通过两个子类共同继承来的子子类
 * 通过virtual 虚继承的方式，变量在内存中只保留一份
 * 而父类则成为虚基类
*******************************************************************/


/**********************************************************************
 * 多态
 * 1.静态多态： 函数重载、运算符重载
 * 2.动态多态： 派生类和基类实现动态绑定
 * 3.virtual 虚函数实现在运行时动态绑定的过程，因此派生类要重写虚函数
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
/***********************************
 * Animal tmp = Cat p
 * 子类可以初始化父类，可以进行类型转换
************************************/
void doSpeak(Animal &p)
{
    p.speak();
}

/**************************************
 * 纯虚函数 virtual void func() = 0;
 * 抽象类
 * 子类必须重写父类虚函数
**************************************/


/*****************************************************************
 * 虚析构 | 纯虚析构
 * 在通过动态多态时，父类指针指向了子类对象，而父类指针销毁时是不会调用子类的析构函数的
 * 因此通过父类的虚析构，来解决子类析构的堆区内存释放
 * 虚析构必须要有定义和声明，即子类也要实现对应的析构方式
******************************************************************/

/****************************************************************
公有继承的方式，通过在基类声明虚函数，表明希望派生类进行覆盖
而在派生类中添加关键字 override 声明改写自己的虚函数
以防止在派生类中由于参数列表的不同产生一个新的函数，但虚函数却没覆盖掉
final 表示不允许被覆盖，即不能再被继承
*****************************************************************/
class Quote {
    public:
        string isbn() const;
        // 除构造函数外的非静态函数都可以是虚函数
        // virtual 只能出现在类内部声明，而不能出现在外部定义
        virtual double net_price(size_t n) const;
};
/***********************************************
派生类声明： class Bulk_quote;
派生时基类必须被定义
派生类在继承基类的虚函数时必须重新定义，以覆盖基类
************************************************/
class Bulk_quote:public Quote {
    public:
        double net_price(size_t n) const override; 
};

/***************************************************************
根据传入的item对象不同，而调用不同的虚函数，实现动态绑定
根据形参决定运行的版本，即在运行时选择函数版本，动态绑定又称运行时绑定
****************************************************************/
double print_total(ostream &os,const Quote &item,size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " <<  item.isbn()  << " # sold: " 
            << n << "total due: " << ret << endl;

    return ret;
}

/******************************************************************
通过公有继承
派生类能够向基类进行隐式的类型转换，是由于派生类对象中含有与基类对应的部分
而不存在基类转向派生类的方式
当派生类初始化基类时只会初始化共同存在的部分，派生类其余部分则会被砍掉
*******************************************************************/

//完善定义Quote基类
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
一个类既可以是基类，也可以是派生类，即通过基类继承得到D1，而D2又通过D1继承而来
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
一般是通过重构的方式添加派生类对象
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
通过直接基类Disc_quote派生出Bulk_quote，间接基类Quote
*******************************************************/
class Bulk_quote:public Disc_quote {
    public:
        Bulk_quote() = default;
        Bulk_quote(const string &book, double p, size_t qty, double disc):
                    Disc_quote(book,p,qty,discount){};
        double net_price(size_t) const override;
};