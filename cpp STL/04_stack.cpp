#include <iostream>
#include <stack>

using namespace std;

/*******************************************************
 * stack<type> s
���ݴ�ȡ��
- push(elem);      ��ջ�����Ԫ��
- pop();           ��ջ���Ƴ���һ��Ԫ��
- top();           ����ջ��Ԫ��
��С������
- empty();          �ж϶�ջ�Ƿ�Ϊ��
- size();           ����ջ�Ĵ�С
********************************************************/
int main() 
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    if (s.empty()) {
        cout << "Stack is empty!" << endl;
        return 0;
    }

    s.pop();

    cout << "The top element is: " << s.top() << endl;
    cout << "The size is: " << s.size() << endl;
}