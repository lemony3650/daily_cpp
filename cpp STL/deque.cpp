#include <iostream>
#include <deque>
using namespace std;

/**********************************************************
 * deque 双端队列
 * 队列连续，但队列间不连续
 * 能够在头尾插入
***********************************************************/
void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); \
                        it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}

//deque构造
void test01() {

	deque<int> d1; //无参构造函数
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int> d2(d1.begin(),d1.end());
	printDeque(d2);

	deque<int>d3(10,100);
	printDeque(d3);

	deque<int>d4 = d3;
	printDeque(d4);

    deque<int>d5;
	d5.assign(10, 100);
}

/********************************
 * deque.empty()
 * deque.size()
 * deque.resize(num)
 * deque.resize(num,elem)
********************************/

/************************************************************************
 * 两端插入操作：
- push_back(elem);          在容器尾部添加一个数据
- push_front(elem);         在容器头部插入一个数据
- pop_back();               删除容器最后一个数据
- pop_front();              删除容器第一个数据

 * 指定位置操作：
- insert(pos,elem);         在pos位置插入一个elem元素的拷贝，返回新数据的位置。
- insert(pos,n,elem);       在pos位置插入n个elem数据，无返回值。
- insert(pos,beg,end);      在pos位置插入[beg,end)区间的数据，无返回值。
- clear();                  清空容器的所有数据
- erase(beg,end);           删除[beg,end)区间的数据，返回下一个数据的位置。
- erase(pos);               删除pos位置的数据，返回下一个数据的位置。
***********************************************************************/

/*************************************************
- at(int idx);     返回索引idx所指的数据
- operator[];      返回索引idx所指的数据
- front();         返回容器中第一个数据元素
- back();          返回容器中最后一个数据元素
***************************************************/
 
/**********************************************
  * sort()
  * sort(iterator beg, iterator end)
***********************************************/
