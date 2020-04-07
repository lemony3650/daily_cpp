#include <iostream>
#include <list>
using namespace std;


/*********************************************************************
 * list ����
- list<T> lst;                list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
- list(beg,end);              ���캯����[beg, end)�����е�Ԫ�ؿ���������
- list(n,elem);               ���캯����n��elem����������
- list(const list &lst);      �������캯����
**********************************************************************/
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//��ֵ
	list<int>L2;
	L2 = L1;

	list<int>L3;
	L3.assign(L2.begin(), L2.end());

	list<int>L4;
	L4.assign(10, 100);
}

/***********************************************************************
- push_back(elem);//������β������һ��Ԫ��
- pop_back();//ɾ�����������һ��Ԫ��
- push_front(elem);//��������ͷ����һ��Ԫ��
- pop_front();//��������ͷ�Ƴ���һ��Ԫ��

- insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
- insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
- insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��

- clear();//�Ƴ���������������
- erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
- erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
- remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
*************************************************************************/

/*******************************************************
- reverse();     ��ת����
- sort();        ��������
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

//��ת������
void test01()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);

	//��ת������Ԫ��
	L.reverse();
	printList(L);

	//����
	L.sort(); //Ĭ�ϵ�������� ��С����
	printList(L);

	L.sort(myCompare); //ָ�����򣬴Ӵ�С
	printList(L);
}
