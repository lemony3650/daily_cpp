#include <iostream>
#include <string>
using namespace std;

/********************************************************************
 * ��ģ�壬����һ��ͨ������� + ��
 * template<typename T>
 * class 
 * ��ģ���޷��Զ������Ƶ�������ָ�����ͣ�����ģ�������Ĭ�ϲ�������
 * ����ʵ�ֵĳ�Ա������Ҫ���ģ������б�
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

//���캯�� ����ʵ��
template<typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

//��Ա���� ����ʵ��
template<typename T1, typename T2>
void Person<T1, T2>::showPerson() {
	cout << "����: " << this->m_Name << " ����:" << this->m_Age << endl;
}

void test01()
{
    // ����ָ��Person<>����
    Person<string, int> p1("yourname",666);
    p1.showPerson();

    Person<string> p2("yourname",1);
    p2.showPerson();
}

/***********************************************
 * ��ģ���г�Ա����ֻ���ں�������ʱ�Żᴴ��
 * ���½������࣬ͨ��������ģ������е���
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

    // �ܹ����е��ã����ڵ���ʱ��û�д˷���
    // ��˺�������ʱ�Żᴴ����Ա����
    // m.func_2();
}

/*****************************************************************
 * ��ģ�������Ϊ�����Ĳ���ʵ�֣�һ���ѡ���һ�ַ�ʽ
 * 1.ָ������ʵ��
 * 2.��ģ�����,ָ����������Ϊģ�� template<typename T1, typename T2>
 * 3.������ģ�廯 template<typename T>
********************************************************************/
void printPerson1(Person<string,int> &p);

template<typename T1, typename T2>
void printPerson2(Person<T1,T2> &P);

template<typename T>
void printPerson3(T &p);

/********************************************************
 * ����̳и��ࣨ��ģ�壩ʱ��Ҫָ������Ĳ�������T
 * ����ָ���������޷������ڴ�
 * ����Ҫ���ָ������T�Ĳ������ͣ�����Ҳ���Ϊģ����
*********************************************************/
template<typename T>
class Base
{
    T m;
};
// �������ָ������
class Son:public Base<int>
{

};
// ģ������̳�ģ�常��
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
 * ���ļ���д��.c/.h�ļ������ӵ�ʱ��
 * 1.��Դ�ļ�����Ҫ����.cppԴ�ļ�
 * 2.������ʵ��д��һ���ļ��У���.hpp�ļ�
*****************************************/

/***************************************************************************
 * ��ģ������Ԫ������ʵ��
 * 1.����ʵ��
 * 2.����ʵ��
****************************************************************************/
//2��ȫ�ֺ��������Ԫ  ����ʵ�� - ��������ģ���������·���������ģ�嶨�壬������Ԫ
template<class T1, class T2> class Person;

//��������˺���ģ�壬���Խ�ʵ��д�����棬������Ҫ��ʵ����д�����ǰ���ñ�������ǰ����
//template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 

template<class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
	cout << "����ʵ�� ---- ������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//1��ȫ�ֺ��������Ԫ   ����ʵ��
	friend void printPerson(Person<T1, T2> & p)
	{
		cout << "������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
	}

	//ȫ�ֺ��������Ԫ  ����ʵ��
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

//1��ȫ�ֺ���������ʵ��
void test01()
{
	Person <string, int >p("Tom", 20);
	printPerson(p);
}

//2��ȫ�ֺ���������ʵ��
void test02()
{
	Person <string, int >p("Jerry", 30);
	printPerson2(p);
}