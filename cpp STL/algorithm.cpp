#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>


using namespace std;


/****************************************************
 * for_each(iterator begin,iterator end, _func)
 * _func自定义函数
 * _func(*it)
*****************************************************/
void print01(int val)
{
    cout << val << endl;
}
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++) 
	{
		v.push_back(i);
	}

	//遍历算法
	for_each(v.begin(), v.end(), print01);
	cout << endl;    
}
/****************************************************************
 * transform(iterator beg1, iterator end1, iterator beg2, _func)
 * 搬运的目标容器必须要提前开辟空间，否则无法正常搬运
 * 搬运过程可以使用_func
****************************************************************/

/********************************************
 * find(iterator beg, iterator end, value)
 - find_if(iterator beg, iterator end, _Pred) 
        _Pred 函数或者谓词（返回bool类型的仿函数）
*********************************************/
//内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test02() 
{
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "没有找到!" << endl;
	}
	else {
		cout << "找到大于5的数字:" << *it << endl;
	}
}

/****************************************************
//查找相邻重复元素
adjacent_find(iterator beg, iterator end);

//二分查找法,在无序序列中不可用
bool binary_search(iterator beg, iterator end, value);

//统计value元素个数
count(iterator beg, iterator end, value);

//按条件统计元素个数
count_if(iterator beg, iterator end, _Pred);
*****************************************************/


/*********************************************************************************
 * sort(iterator beg, iterator end, _Pred);
 * random_shuffle(iterator beg, iterator end);
 * merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 * reverse(iterator beg, iterator end);
**********************************************************************************/




/**************************************************************
 * 拷贝和替换
- copy                   // 容器内指定范围的元素拷贝到另一容器中
        copy(iterator beg, iterator end, iterator dest);
- replace                // 将容器内指定范围的旧元素修改为新元素
        replace(iterator beg, iterator end, oldvalue, newvalue);
- replace_if             // 容器内指定范围满足条件的元素替换为新元素
        replace_if(iterator beg, iterator end, _pred, newvalue);
- swap                   // 互换两个容器的元素
        swap(container c1, container c2);
*****************************************************************/







/*******************************************************************
 * 算术生成算法
 * // 算区间内 容器元素累计总和
- accumulate(iterator beg, iterator end, value);
 * value 起始值
 * // 向容器中填充指定的元素
- fill(iterator beg, iterator end, value);
 * value 填充的值
*******************************************************************/



/*************************************************************
 * 常用集合算法
- set_intersection            // 求两个容器的交集
    1.求交集的两个集合必须的有序序列
    2.目标容器开辟空间需要从两个容器中取小值
    3.set_intersection返回值既是交集中最后一个元素的位置
- set_union                   // 求两个容器的并集
    1.两个集合必须的有序序列
    2.目标容器开辟空间需要两个容器相加
    3.set_union返回值既是并集中最后一个元素的位置
- set_difference              // 求两个容器的差集
    1.差集的两个集合必须的有序序列
    2.目标容器开辟空间需要从两个容器取较大值
    3.set_difference返回值既是差集中最后一个元素的位置
***************************************************************/
class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
    {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//取两个里面较小的值给目标容器开辟空间
	vTarget.resize(min(v1.size(), v2.size()));

	//返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = 
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());


	//取两个容器的和给目标容器开辟空间
	vTarget.resize(v1.size() + v2.size());
 	//返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = 
        set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());   


	//取两个里面较大的值给目标容器开辟空间
	vTarget.resize( max(v1.size() , v2.size()));

	//返回目标容器的最后一个元素的迭代器地址
	cout << "v1与v2的差集为： " << endl;
	vector<int>::iterator itEnd = 
        set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;

	cout << "v2与v1的差集为： " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;



	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}