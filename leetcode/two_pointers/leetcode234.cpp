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
 * ������Ļ����ж�
 * 1.�������������������ԣ����������������
 * 2.����ջ�����ԣ���ջ�����෴���ж�
 * 3.˫ָ�룬Ѱ���м�λ�ã��������벿�ֽ��з�ת����
 * 4.˫ָ�룬��Ѱ�������м�λ�õ�ͬʱ��������ǰ�벿�ֽ��з�ת
***********************************************************/

/**************************************************
 *                  ִ��ʱ��(ms)        �ڴ�(MB)
 * ����|ջ             40              14.9
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

        // ����ָ��
        ListNode *fast = head;
        ListNode *slow = head;
        // Ѱ���м�λ��
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // ��ת���� tmp������� nextnode��ڶ���
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

        // ����ָ��
        ListNode *fast = head;
        ListNode *slow = head;
        // slow�ڵ�ǰ��
        ListNode *p = NULL;
        ListNode *prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            p = slow;
            slow = slow->next;
            fast = fast->next->next;
    
            p->next = prev;
            prev = p;
        }

        // �ж���������ʱ��slow�����м�λ��,ֻ��Ҫ�Ƚ�ǰ��������
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

    // ����洢��������λ˫ָ����л����жϣ� �ռ�O(n)
    cout << s.isPalindrome_1(head) << endl;
    s.dump_slist(head);
    // ��ջ-��ջ�Ƚ�
    cout << s.isPalindrome_2(head) << endl;
    s.dump_slist(head);
    // ���м�λ��+��ת����+�Ƚ�
    cout << s.isPalindrome_3(head) << endl;
    s.dump_slist(head);
    // ����������ͬʱ��תǰ�벿��
    cout << s.isPalindrome_4(head) << endl;
    s.dump_slist(head);

   return 0;
}