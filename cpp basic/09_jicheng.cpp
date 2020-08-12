#include <iostream>
using namespace std;

/****************************************************************************
 * �̳� 
 * class ���� : �̳з�ʽ ����1,�̳з�ʽ ����2
 * �̳з�ʽָ��������Ի���ķ���Ȩ�ޣ�
 * 1.���� 2.���� 3.˽��
 * ���м̳У� 1.���� 2.���� 3.˽��   ������ֻ�ܷ��ʻ���Ĺ��кͱ���
 * �����̳У� 1.���� 2.���� 3.˽��   ������ֻ�ܷ��ʻ���ı���
 * ˽�м̳У� 1.˽�� 2.˽�� 3.˽��   ������Ի��඼���ܷ���
 * ���������ڵ����Դ������������ķ���Ȩ��
--------------------------------------------------------------
 * ������̳л��࣬����˽�г�Ա���Ǵ��ڵģ�ֻ�ǲ��ܷ��ʣ�����������
 * �������ౣ���������зǾ�̬��Ա���ڴ���������
 ---------------------------------------------
 * �����������Ĺ�������������������ࣨ�������ࣩ
 *  1.���л���Ĺ��� ���������๹��
 *  2.�������������������л�������
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
        // m_C ��������ʲ�������˽��
    }
    // ͬʱ������������ʲ���m_B 
};

class son2 : protected Base
{
public:
    void func()
    {
        m_A = 10;
        m_B = 20;
        // m_C ��������ʲ�������˽��
    }
    // ͬʱ������������ʲ����κ�
};

class son3 : protected Base
{
public:
    void func()
    {
        //��������ʲ�������˽��
    }
    // ͬʱ������������ʲ����κ�
};

/*****************************************************************
 * ��̳к������ - ���μ̳й�ϵ
   ���ڴ�ͬһ������̳������������࣬��ͨ���������๲ͬ�̳�����������
   1. ����ͨ���������������ʶ��
   2. ��һ��ͨ��ֻ��Ҫһ���ڴ棬��ν���������
 * ͨ��virtual ��̳еķ�ʽ���������ڴ���ֻ����һ��,���и�vbptrָ��
   ���������Ϊ�����
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

    // vbptr �����ָ��  ->  ָ��vbtable  -> a_Age
}

/**********************************************************************
 * ��̬���ܹ����㿪��ԭ����֯�ṹ�������ɶ���ǿ������չά��
 * 1.��̬��̬�� �������ء����������
 * 2.��̬��̬�� ������ͻ���ʵ�ֶ�̬��
 *   virtual �麯��ʵ��������ʱ��̬�󶨵Ĺ��̣����������Ҫ��д�麯��
 *   ͨ��������������β�
***********************************************************************/
class Animal 
{
    public:
        // �麯��
        virtual void speak(){ cout << "animal is speaking..." << endl;}
};

class Cat:public Animal
{
    public:
        // Virtual �ɼӿɲ���
        virtual void speak(){cout << "cat is speaking..." << endl;}
};
/*******************************************************
 * Animal tmp = Cat p  ������Գ�ʼ�����࣬��������ת��
 * ���������麯�������ַ��󶨣��ڱ���׶ν��е�ַ����
 * ��Ҫ�麯��ʹ�õ�ַ���
*******************************************************/
void doSpeak(Animal &p)
{
    p.speak();
}

/*************************************************************************
 * ��̬����
 * 1. ����ռһ���ֽ�
 * 2. ͬһ����Ĳ�ͬʵ������һ���麯����(����ʱ����)
      ��ÿ��������һ��ָ��һ��ָ������(�麯����)��ָ��vfptr
 *   �麯�������ڲ�
      1. ����һ��ָ��vfptr -> vftable &Animal::speak  (ռ�ĸ��ֽ�)
 *   �������ڲ� 
      1. ������ȫ�̳л���ĳ�Ա���ԣ�����ָ������麯�����ָ��vfptr
      2. ��������дʱ��ָ��vfptr ��ָ�����������ڲ��ĺ���  -> vftable &Cat::speak
      3. ��������Ҳ�����麯��ʱ�����ڻ����麯���������ӣ����sizeof()����
      4. ��������̳�ʱ����˳�򴴽��麯�������vfptr
--------------------------------------------------------------------------
 * ���麯��������������һ�����麯�����࣬��Ϊ�����ࣨ�޷�ʵ��������, �޺�����
  1. һ�����ڻ�����麯��û���ã��ò��������д�ɴ��麯��
  2. virtual void func() = 0;
  3. ���������д�����麯��
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
 * ������ | ��������
 * ��ͨ����̬��̬ʱ������ָ��ָ����������󣬶�����ָ������ʱ�ǲ�������������������
   ���ͨ�����������������������������Ķ����ڴ��ͷ�
   ����������Ҫ�ж����������������ҲҪʵ�ֶ�Ӧ��������ʽ
 * �������������ڻ�����Ҳ�о���ʵ��
******************************************************************/

/****************************************************************
���м̳еķ�ʽ��
    ͨ���ڻ��������麯��������ϣ����������и���
    ������������ӹؼ��� override ������д�Լ����麯��
    �Է�ֹ�������������ڲ����б�Ĳ�ͬ����һ���µĺ��������麯��ȴû���ǵ�
    final ��ʾ���������ǣ��������ٱ��̳�
------------------------------------------------------------------
 * ���ݴ����item����ͬ�������ò�ͬ���麯����ʵ�ֶ�̬��
 * �����βξ������еİ汾����������ʱѡ�����汾����̬���ֳ�����ʱ��
*****************************************************************/
class Quote {
public:
    string isbn() const;
    // �����캯����ķǾ�̬�������������麯��

    // virtual ֻ�ܳ��������ڲ������������ܳ������ⲿ����
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
 * ͨ�����м̳�
    �������ܹ�����������ʽ������ת��������������������к���������Ӧ�Ĳ���
    �������ڻ���ת��������ķ�ʽ
    ���������ʼ������ʱֻ���ʼ����ͬ���ڵĲ��֣����������ಿ����ᱻ����
-------------------------
���ƶ���Quote����
*******************************************************************/
class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
        bookNo(book),price(sales_price){}

    string isbn() const {return bookNo;};
    virtual double net_price(size_t n) const
                            {return n * price;};

    // ����������
    virtual ~Quote() = default;

    //�����еľ�̬��Ա�������������ٸ�������Ψһ���ڵ�һ��ʵ������
    //��ѭ���ʿ���
    static int flag;
private:
    string bookNo;
protected:
    double price = 0.0;
};

// ����������
class Bulk_quote:public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc):
                Quote(book,p),min_qty(qty),discount(discount){};

    // �������Ա�Լ��ĳ�Ա����ʵ��       
    double net_price(size_t cnt) const override
    {
        if(cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else 
            return cnt * price;
    };
    // public�̳� �����ڻ���ĺ����ͳ�Ա

    //using ���Ըı����еķ��ʿ���
    using Quote::price;
private:
    size_t min_qty = 0;                 // �����ۿ۵���С������
    double discount = 0.0;              // �ۿ۶�
};


/**********************************************************************
 * һ����ȿ����ǻ��࣬Ҳ�����������࣬��ͨ������̳еõ�D1����D2��ͨ��D1�̳ж���
   ���Ϊ��ֹ����Ҫ�ļ̳У����������ؼ��� final
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
 * һ����ͨ���ع��ķ�ʽ������������
    ��ֻ���湺�������ۿ�ֵ��������۴�ʩ��������ȥ��
    ����ֱ�Ӷ���Disc_quote���󣬱���ͨ������������net_price��ʽʵ��
*****************************************************************/
class Disc_quote:public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price,size_t qty,double disc):
        Quote(book,price),quantity(qty),discount(disc){}

    // ���麯������ʵ�����壬�����û�ʹ����
    double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};
/*******************************************************
 * ͨ��ֱ�ӻ��� Disc_quote ������ Bulk_quote����ӻ���Quote
*******************************************************/
class Bulk_quote:public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc):
                Disc_quote(book,p,qty,discount){};
    double net_price(size_t) const override;
};