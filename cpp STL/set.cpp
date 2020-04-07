#include <iostream>
#include <set>
using namespace std;

/************************************
 * set ������Ψһ�ؼ���
 * ��������������ʱ���Զ���������
 * �������ķ�ʽ
 * multiset �����ظ�
************************************/

/**************************************************************
 * set ���弰��ʼ��
 * set<T> st;               Ĭ�Ϲ���
 * set(const set &st);      ��������
**************************************************************/
void printSet(set<int> &s)
{
    for(set<int>::iterator it = s.begin();it != s.end(); it++)
        cout << *it <<  endl; 
}
void test01()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
    
	//��������
	set<int>s2(s1);

	//��ֵ
	set<int>s3;
	s3 = s2;
}

/**********************************************
 * set insert and erase
 * insert(elem)
 * erase(elem) || erase(pod) || erase(beg,end)
 * clear()
 * ������Ԫ��λ�ã�û��ͷβ����ķ�ʽ
**********************************************/

/*******************************************
 * find(key)  
 * ���ز��ҵ���Ԫ�����������򷵻�end()
 * count(key)
********************************************/ 
void test02()
{
    set<int> s1;

    s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

    set<int>::iterator pos = s1.find(30);
    if( pos != s1.end())
        cout << *pos << endl;

    int count = s1.count(30);
}

/***********************************************
 * set insert ��������ʱ�᷵��������ʾ�Ƿ����ɹ�
 * multiset   ����������
***********************************************/
void test03()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);

}

/*****************************************************************
 * pair����������
 * pair<type,type> p(value,value2)
 * pair<type,type> p = make_pair(value,value2)
 * first
 * second
******************************************************************/ 
void test04()
{
	pair<string, int> p(string("Tom"), 20);
	cout << "������ " <<  p.first << " ���䣺 " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "������ " << p2.first << " ���䣺 " << p2.second << endl;
}

/*****************************************************
 * ���÷º����ı��������
 * ָ���������
 * ()�������صķº��� 
 *****************************************************/
class MyCompare
{
    public:
        bool operator()(int v1,int v2){
            return v1 > v2;
        }
};

void test05()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);

	//Ĭ�ϴ�С����
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//ָ���������
	set<int,MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);

	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
} 

/*****************************************
 * �Զ���set����
 * �Զ���Ƚϲ���
******************************************/
class Person 
{
    public:
        Person(string name,int age):mName(name),mAge(age){};

        string mName;
        int    mAge;
};
class comparePerson
{
    public:
        bool operator()(const Person &p1,const Person &p2)
        {
            return p1.mAge > p2.mAge;
        }
};
void test06()
{
	set<Person, comparePerson> s;

	Person p1("����", 23);
	Person p2("����", 27);
	Person p3("�ŷ�", 25);
	Person p4("����", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "������ " << it->mName << " ���䣺 " << it->mAge << endl;
	}
}
