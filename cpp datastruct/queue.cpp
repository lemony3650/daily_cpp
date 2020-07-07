#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/************************************************
 * 单独的队列实现
 * 通过动态数组和一个队头指针实现队列
 * vector<int> data
 * int p_front
 * 1.入队  push_back
 * 2.出队  p_front++
************************************************/
class myQueue {
private:
    vector<int> data;
    int p_front;

public:
    myQueue() {
        p_front = 0;
    }

    bool enQueue(int value) {
        data.push_back(value);
        return true;
    }

    bool deQueue() {
        if (isEmpty()) 
            return false;

        p_front++;
        return true;
    }

    int getFront() {
        return data[p_front];
    }

    bool isEmpty() {
        return p_front >= data.size();
    }

    void showQueue() {
        for (vector<int>::iterator it = data.begin() + p_front; it != data.end(); it++)
            cout << *it << " ";

        cout << endl;
    }
};


void test01()
{
    myQueue q;

    q.enQueue(5);
    q.enQueue(3);
    q.showQueue();

    q.deQueue();
    q.showQueue();

    q.deQueue();
    q.showQueue();
}

/*****************************************************
 * 实现循环队列
 * 通过一个动态数组和两个头尾指针
 * 通过维护指针的方式, 有了头尾指针就不需要push_back|pop
******************************************************/
class myCirculQueue {
private:
    vector<int> data;
    int p_front;
    int p_tail;
    int size;

public:
    myCirculQueue(int length) {
        data.resize(length);
        p_front = -1;
        p_tail = -1;
        size = length;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        if (isEmpty())
            p_front = 0;

        p_tail = (p_tail + 1) % size;
        data[p_tail] = value;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) 
            return false;

        // 只存在一个元素了
        if (p_front == p_tail) {
            p_front = -1;
            p_tail  = -1;
            return true;
        }

        p_front= (p_front + 1) % size;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return data[p_front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return data[p_tail];        
    }

    bool isEmpty() {
        return p_front == -1;
    }
    bool isFull() {
        return ((p_tail + 1) % size) == p_front; 
    }
};

/*****************************************
 * 通过deque<>容器实现队列
 * 
******************************************/
int test02()
{
    queue<int> q;

    q.push(5);
    q.push(3);
    q.push(15);
    q.push(13);

    if (q.empty()) {
        cout << "Queue is empty" << endl;
        return 0;
    }

    q.pop();

    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
}

int main()
{
    test02();

    system("pause");
    return 0;
}