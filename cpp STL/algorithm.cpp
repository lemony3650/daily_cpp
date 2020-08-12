#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>


using namespace std;


/****************************************************
 * for_each(iterator begin,iterator end, _func)
 * _func�Զ��庯��
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

	//�����㷨
	for_each(v.begin(), v.end(), print01);
	cout << endl;    
}
/****************************************************************
 * transform(iterator beg1, iterator end1, iterator beg2, _func)
 * ���˵�Ŀ����������Ҫ��ǰ���ٿռ䣬�����޷���������
 * ���˹��̿���ʹ��_func
****************************************************************/

/********************************************
 * find(iterator beg, iterator end, value)
 - find_if(iterator beg, iterator end, _Pred) 
        _Pred ��������ν�ʣ�����bool���͵ķº�����
*********************************************/
//������������
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
		cout << "û���ҵ�!" << endl;
	}
	else {
		cout << "�ҵ�����5������:" << *it << endl;
	}
}

/****************************************************
//���������ظ�Ԫ��
adjacent_find(iterator beg, iterator end);

//���ֲ��ҷ�,�����������в�����
bool binary_search(iterator beg, iterator end, value);

//ͳ��valueԪ�ظ���
count(iterator beg, iterator end, value);

//������ͳ��Ԫ�ظ���
count_if(iterator beg, iterator end, _Pred);
*****************************************************/


/*********************************************************************************
 * sort(iterator beg, iterator end, _Pred);
 * random_shuffle(iterator beg, iterator end);
 * merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 * reverse(iterator beg, iterator end);
**********************************************************************************/




/**************************************************************
 * �������滻
- copy                   // ������ָ����Χ��Ԫ�ؿ�������һ������
        copy(iterator beg, iterator end, iterator dest);
- replace                // ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
        replace(iterator beg, iterator end, oldvalue, newvalue);
- replace_if             // ������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
        replace_if(iterator beg, iterator end, _pred, newvalue);
- swap                   // ��������������Ԫ��
        swap(container c1, container c2);
*****************************************************************/







/*******************************************************************
 * ���������㷨
 * // �������� ����Ԫ���ۼ��ܺ�
- accumulate(iterator beg, iterator end, value);
 * value ��ʼֵ
 * // �����������ָ����Ԫ��
- fill(iterator beg, iterator end, value);
 * value ����ֵ
*******************************************************************/



/*************************************************************
 * ���ü����㷨
- set_intersection            // �����������Ľ���
    1.�󽻼����������ϱ������������
    2.Ŀ���������ٿռ���Ҫ������������ȡСֵ
    3.set_intersection����ֵ���ǽ��������һ��Ԫ�ص�λ��
- set_union                   // �����������Ĳ���
    1.�������ϱ������������
    2.Ŀ���������ٿռ���Ҫ�����������
    3.set_union����ֵ���ǲ��������һ��Ԫ�ص�λ��
- set_difference              // �����������Ĳ
    1.����������ϱ������������
    2.Ŀ���������ٿռ���Ҫ����������ȡ�ϴ�ֵ
    3.set_difference����ֵ���ǲ�����һ��Ԫ�ص�λ��
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
	//ȡ���������С��ֵ��Ŀ���������ٿռ�
	vTarget.resize(min(v1.size(), v2.size()));

	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	vector<int>::iterator itEnd = 
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());


	//ȡ���������ĺ͸�Ŀ���������ٿռ�
	vTarget.resize(v1.size() + v2.size());
 	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	vector<int>::iterator itEnd = 
        set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());   


	//ȡ��������ϴ��ֵ��Ŀ���������ٿռ�
	vTarget.resize( max(v1.size() , v2.size()));

	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	cout << "v1��v2�ĲΪ�� " << endl;
	vector<int>::iterator itEnd = 
        set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;

	cout << "v2��v1�ĲΪ�� " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;



	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}