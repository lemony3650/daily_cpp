#include <iostream>
#include <map>
using namespace std;

/***************************************
 * map ����
 * map��Ԫ��Ϊ��ֵ�ԣ�pair����
 * ����Ԫ�ؼ�ֵ�Զ�����
 * ������ʵ��
****************************************/

/************************************************
 * map ����
 * map<type,type> mp
 * map(const map &map)  �������캯��
 * map& operator=(const map &mp) ����map����=
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

    map<int, int>m2(m); //��������
    printMap(m2);

	map<int, int>m3;
	m3 = m2; //��ֵ ��Ҫ����=
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

	//ɾ��
	m.erase(m.begin());
	m.erase(3);

	//���
	m.erase(m.begin(),m.end());
	m.clear();
}
/*******************************************
 * find(key)  
 * ���ز��ҵ���Ԫ�����������򷵻�end()
 * count(key)
 * ͳ��key��Ԫ�ظ���
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
 * map ����
 * ����key��С���������Ĭ�Ͻ�������
 * ͨ���޸ķº������ı�Ĭ�ϵ��������
*******************************************/
class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void test01() 
{
	//Ĭ�ϴ�С��������
	//���÷º���ʵ�ִӴ�С����
	map<int, int, MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}