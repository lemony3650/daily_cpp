#include <iostream>
#include <list>
using namespace std;


/*********************************************************************
 * list 链表
- list<T> lst;                list采用采用模板类实现,对象的默认构造形式：
- list(beg,end);              构造函数将[beg, end)区间中的元素拷贝给本身。
- list(n,elem);               构造函数将n个elem拷贝给本身。
- list(const list &lst);      拷贝构造函数。
**********************************************************************/
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//赋值
	list<int>L2;
	L2 = L1;

	list<int>L3;
	L3.assign(L2.begin(), L2.end());

	list<int>L4;
	L4.assign(10, 100);
}

/***********************************************************************
- push_back(elem);//在容器尾部加入一个元素
- pop_back();//删除容器中最后一个元素
- push_front(elem);//在容器开头插入一个元素
- pop_front();//从容器开头移除第一个元素

- insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
- insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
- insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。

- clear();//移除容器的所有数据
- erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
- erase(pos);//删除pos位置的数据，返回下一个数据的位置。
- remove(elem);//删除容器中所有与elem值匹配的元素。
*************************************************************************/

/*******************************************************
- reverse();     反转链表
- sort();        链表排序
*******************************************************/
void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int val1 , int val2)
{
	return val1 > val2;
}

//反转和排序
void test01()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);

	//反转容器的元素
	L.reverse();
	printList(L);

	//排序
	L.sort(); //默认的排序规则 从小到大
	printList(L);

	L.sort(myCompare); //指定规则，从大到小
	printList(L);
}
