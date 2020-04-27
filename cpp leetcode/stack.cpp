#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*****************************************
 * stack
 * 入栈出栈都是尾部节点出栈
******************************************/
class myStack {
private:
    vector<int> data;
public:
    void push(int value) {
        data.push_back(value);
    }

    int getTop() {
        return data.back();
    }

    bool pop() {
        if (isEmpty()) {
            return false;
        }

        data.pop_back();
        return true;
    }

    void showStack() {
        if (isEmpty())
            cout << "stack is null" << endl;

        for (vector<int>::iterator it = data.begin(); it != data.end(); it++)
            cout << *it << " ";

        cout << endl;
    }

    bool isEmpty() {
        return data.empty();
    }
};

void test01()
{
    myStack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.showStack();

    s.pop();
    s.showStack();

    s.pop();
    s.pop();
    s.showStack();
}

/*******************************************************
 * 内置的stack栈容器实现
 * 1 push(elem)
 * 2 pop()
 * 3 top()
 * 4 size() | empty()
*******************************************************/
void test02()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    if (s.empty()) {
        cout << "Stack is empty!" << endl;
    }

    s.pop();

    cout << "The top element is: " << s.top() << endl;
    cout << "The size is: " << s.size() << endl;
}



int main()
{
    test02();

    return 0;
}