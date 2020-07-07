#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

typedef struct _listnode {
    int val;
    _listnode *next;
}ListNode;


/***********************************************************
 * 单链表的回文判断
 * 1.利用数组的随机访问特性，将单链表存入数组
 * 2.利用栈的特性，出栈方向相反来判断
 * 3.双指针，寻找中间位置，对链表后半部分进行反转操作
 * 4.双指针，在寻找链表中间位置的同时，对链表前半部分进行反转
***********************************************************/

/**************************************************
 *                  执行时间(ms)        内存(MB)
 * 数组|栈             40              14.9
 * 3                   32              13.9
 * 4                   20              13.9
***************************************************/

class Solution {
public:

    bool isPalindrome_1(ListNode *head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < v.size()/2; i++) {
            if (v[i] != v[v.size()-1-i])
                return false;
        }
        return true;
    }

    bool isPalindrome_2(ListNode *head) {
        stack<int> s;
        ListNode *p = head;
        int count = 0;

        while (p) {
            s.push(p->val);
            p = p->next;
            count++;
        }

        p = head;
        count = count/2;
        while (p && count--)  {
            if (p->val != s.top())
                return false;
            s.pop();
            p = p->next;
        }
        return true;
    }

    bool isPalindrome_3(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return true;

        // 快慢指针
        ListNode *fast = head;
        ListNode *slow = head;
        // 寻找中间位置
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 反转链表 tmp存第三个 nextnode存第二个
        ListNode *curNode = slow, *nextNode = slow->next;
        while (nextNode) {
            ListNode *tmp = nextNode->next;

            nextNode->next = curNode;
            curNode = nextNode;
            nextNode = tmp;
        }

        slow->next = nullptr;
        ListNode *p_head = head;

        while(p_head && curNode) {
            if (p_head->val != curNode->val)
                return false;

            p_head = p_head->next;
            curNode = curNode->next;
        }
        return true;
    }

    bool isPalindrome_4(ListNode *head) {

        if (head == NULL || head->next == NULL)
            return true;

        // 快慢指针
        ListNode *fast = head;
        ListNode *slow = head;
        // slow节点前后
        ListNode *p = NULL;
        ListNode *prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            p = slow;
            slow = slow->next;
            fast = fast->next->next;
    
            p->next = prev;
            prev = p;
        }

        // 判断奇数链表时，slow跳过中间位置,只需要比较前后两部分
        if (fast)
            slow = slow->next;

        while (p) {
            if (p->val != slow->val)
                return false;

            p = p->next;
            slow = slow->next;
        }
        return true;
    }

    int insertAtTail(ListNode* &head, int elem) {
        ListNode *pNode = (ListNode *)malloc(sizeof(ListNode));
        pNode->val = elem;

        if (head == NULL) {
            head = pNode;
            pNode->next = NULL;
        }

        ListNode* p = head;
        while (NULL != p->next) 
            p = p->next;

        p->next = pNode;
        pNode->next = NULL;
    }
    void  dump_slist(ListNode *head) {
        if (NULL == head)
            cout << "head is null" << endl;
            
        ListNode *p = head;
        while (NULL != p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

};

int main()
{
    ListNode *head = NULL;
    Solution s;
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(10);

    for (auto i : v) 
        s.insertAtTail(head,i);

    // 数组存储，利用首位双指针进行回文判断， 空间O(n)
    cout << s.isPalindrome_1(head) << endl;
    s.dump_slist(head);
    // 入栈-出栈比较
    cout << s.isPalindrome_2(head) << endl;
    s.dump_slist(head);
    // 找中间位置+反转链表+比较
    cout << s.isPalindrome_3(head) << endl;
    s.dump_slist(head);
    // 快慢遍历的同时反转前半部分
    cout << s.isPalindrome_4(head) << endl;
    s.dump_slist(head);

   return 0;
}