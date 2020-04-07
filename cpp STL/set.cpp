#include <iostream>
#include <set>
using namespace std;

/************************************
 * set 容器，唯一关键字
 * 关联容器，插入时被自动进行排序
 * 二叉树的方式
 * multiset 允许重复
************************************/

/**************************************************************
 * set 定义及初始化
 * set<T> st;               默认构造
 * set(const set &st);      拷贝构造
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
    
	//拷贝构造
	set<int>s2(s1);

	//赋值
	set<int>s3;
	s3 = s2;
}

/**********************************************
 * set insert and erase
 * insert(elem)
 * erase(elem) || erase(pod) || erase(beg,end)
 * clear()
 * 不基于元素位置，没有头尾插入的方式
**********************************************/

/*******************************************
 * find(key)  
 * 返回查找到的元素索引，否则返回end()
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
 * set insert 插入数据时会返回数据提示是否插入成功
 * multiset   不会检测数据
***********************************************/
void test03()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);

}

/*****************************************************************
 * pair迭代器创建
 * pair<type,type> p(value,value2)
 * pair<type,type> p = make_pair(value,value2)
 * first
 * second
******************************************************************/ 
void test04()
{
	pair<string, int> p(string("Tom"), 20);
	cout << "姓名： " <<  p.first << " 年龄： " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
}

/*****************************************************
 * 利用仿函数改变排序规则
 * 指定排序规则
 * ()进行重载的仿函数 
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

	//默认从小到大
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则
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
 * 自定义set类型
 * 自定义比较操作
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

	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->mName << " 年龄： " << it->mAge << endl;
	}
}
