#include <iostream>
using namespace std;

#include <queue>

/*******************************************************
 * queue<type> q    ��ʵ���������Ͷ���queue
���ݴ�ȡ��
- push(elem);             ����β���Ԫ��
- pop();                  �Ӷ�ͷ�Ƴ���һ��Ԫ��
- back();                 �������һ��Ԫ��
- front();                ���ص�һ��Ԫ��
��С������
- empty();            �ж϶�ջ�Ƿ�Ϊ��
- size();             ����ջ�Ĵ�С
**************************************************************/
int main()
{
    queue<int> q;

    q.push(5);
    q.push(13);
    q.push(8);
    q.push(6);

    if (q.empty()) {
        cout << "Queue is empty!" << endl;
        return 0;
    }
   
    q.pop();
   
    cout << "The first element is: " << q.front() << endl;
    cout << "The last element is: " << q.back() << endl;
    cout << "The size is: " << q.size() << endl;
}