#include <iostream>
#include <map>
using namespace std;

/***************************************
 * map 容器
 * map中元素为键值对，pair类型
 * 根据元素键值自动排序
 * 二叉树实现
****************************************/

/************************************************
 * map 定义
 * map<type,type> mp
 * map(const map &map)  拷贝构造函数
 * map& operator=(const map &mp) 重载map类型=
 * 1.first = key
 * 2.second = value
*************************************************/
void printMap(map<int,int> &m)
{
    for(map<int,int>::iterator it = m.begin();it != m.end();it++)
        cout << it->first << it->second << endl;
}
void test01()
{
    map<int,int> m;

    m.insert(pair<int,int>(1,10));
    m.insert(make_pair<int,int>(2,20));
    printMap(m);

    map<int, int>m2(m); //拷贝构造
    printMap(m2);

	map<int, int>m3;
	m3 = m2; //赋值 需要重载=
	printMap(m3);
}

/*****************************************************
 * map<int,int> m;
 * m.size() | m.empty() | m.swap(m1)
 * 				 1
******************************************************/

/***********************************************
 * map insert | map erase
 * insert(elem)
 * erase(pos) || erase(begin,end) || erase(key)
 * clear()
***********************************************/
void test02()
{
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
    m.insert(make_pair<int,int>(2,20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40; 

	printMap(m);

	//删除
	m.erase(m.begin());
	m.erase(3);

	//清空
	m.erase(m.begin(),m.end());
	m.clear();
}
/*******************************************
 * find(key)  
 * 返回查找到的元素索引，否则返回end()
 * count(key)
 * 统计key的元素个数
********************************************/ 
void test03()
{
	map<int,int> m;

	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));

	map<int,int>::iterator pos = m.find(3);
	int count = m.count(3);

}


/******************************************
 * map 排序
 * 按照key大小的排序规则默认进行排序
 * 通过修改仿函数，改变默认的排序规则
*******************************************/
class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void test01() 
{
	//默认从小到大排序
	//利用仿函数实现从大到小排序
	map<int, int, MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}