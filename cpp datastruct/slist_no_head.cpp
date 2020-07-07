#include <iostream>
using namespace std;


typedef struct _listnode {
    int val;
    _listnode *next;
}ListNode;

class singlelist_nhead 
{
public:

    int insertAtHead(ListNode* &head, int elem) {
        ListNode *pNode = (ListNode *)malloc(sizeof(ListNode));
        pNode->val = elem;

        if (head == NULL) {
            head = pNode;
            pNode->next = NULL;
        }
        pNode->next = head;
        head = pNode;
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

    int deleteHead(ListNode* &head, int& elem) {
        if (NULL == head)
            return false;

        ListNode *pNode = head;
        head = head->next;
        elem = pNode->val;
        free(pNode);

        return true;
    }

    int deleteTail(ListNode* &head, int& elem) {
        if (NULL == head)
            return false;

        if (NULL == head->next) {
            elem = head->val;
            free(head);
            head = NULL;

            return true;
        }

        ListNode *p = head;
        ListNode *q = p;
        while (NULL != p->next) {
            q = p;
            p = p ->next;
        }
      
        elem = p->val;
        q->next = NULL;
        free(p);

        return true;
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
