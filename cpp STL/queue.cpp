#include <iostream>
using namespace std;

#include <queue>

/*******************************************************
 * queue<type> q    自实现容器类型队列queue
数据存取：
- push(elem);             往队尾添加元素
- pop();                  从队头移除第一个元素
- back();                 返回最后一个元素
- front();                返回第一个元素
大小操作：
- empty();            判断堆栈是否为空
- size();             返回栈的大小
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