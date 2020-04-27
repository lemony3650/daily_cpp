#include <iostream>
#include <deque>
using namespace std;

/**********************************************************
 * deque ˫�˶���
 * ���������������м䲻����
 * �ܹ���ͷβ����
***********************************************************/
void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); \
                        it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}

//deque����
void test01() {

	deque<int> d1; //�޲ι��캯��
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
 * ���˲��������
- push_back(elem);          ������β�����һ������
- push_front(elem);         ������ͷ������һ������
- pop_back();               ɾ���������һ������
- pop_front();              ɾ��������һ������

 * ָ��λ�ò�����
- insert(pos,elem);         ��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
- insert(pos,n,elem);       ��posλ�ò���n��elem���ݣ��޷���ֵ��
- insert(pos,beg,end);      ��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
- clear();                  �����������������
- erase(beg,end);           ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
- erase(pos);               ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
***********************************************************************/

/*************************************************
- at(int idx);     ��������idx��ָ������
- operator[];      ��������idx��ָ������
- front();         ���������е�һ������Ԫ��
- back();          �������������һ������Ԫ��
***************************************************/
 
/**********************************************
  * sort()
  * sort(iterator beg, iterator end)
***********************************************/
