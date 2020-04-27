#include <iostream>
#include <stack>

using namespace std;

/*******************************************************
 * stack<type> s
数据存取：
- push(elem);      向栈顶添加元素
- pop();           从栈顶移除第一个元素
- top();           返回栈顶元素
大小操作：
- empty();          判断堆栈是否为空
- size();           返回栈的大小
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