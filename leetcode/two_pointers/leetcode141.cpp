#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

typedef struct _listnode {
    int val;
    _listnode *next;
}ListNode;

/**********************************************************
 * 判断单链表是否有环路
 * 1.SET的方法 | MAP的方法，存入元素的值和个数          
 * 2.根据地址唯一性，存入元素的地址
 * 3.双指针的方法，步长为一，快慢指针总会相遇到，若无环则退出
**********************************************************/

/**********************************************
 *              执行时间(ms)        内存(MB)
 * set              40              10.1
 * map              24              10.6
 * point            8               7.7
***********************************************/

class Solution {
public:

    // 双指针
    bool hasCycle_1(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)   
                return true;
        }
        return false;
    }

    // map计数  
    bool hasCycle_2(ListNode *head) {
        unordered_map<ListNode *, int> m;

        while (head) {
            m[head]++;
            if (m[head] > 1)
                return true;
            head = head->next;
        }
        return false;
    }

    // Set存储 
    bool hasCycle_3(ListNode *head) {
        set<ListNode *> arr;
        ListNode *q = head;
        int count = 0;
        while (q)
        {
            if (arr.count(q))
                return true;
            else    
                arr.insert(q);

            q = q->next;
        }
        return false;
         
    }
};