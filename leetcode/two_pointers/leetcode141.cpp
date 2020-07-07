#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

typedef struct _listnode {
    int val;
    _listnode *next;
}ListNode;

/**********************************************************
 * �жϵ������Ƿ��л�·
 * 1.SET�ķ��� | MAP�ķ���������Ԫ�ص�ֵ�͸���          
 * 2.���ݵ�ַΨһ�ԣ�����Ԫ�صĵ�ַ
 * 3.˫ָ��ķ���������Ϊһ������ָ���ܻ������������޻����˳�
**********************************************************/

/**********************************************
 *              ִ��ʱ��(ms)        �ڴ�(MB)
 * set              40              10.1
 * map              24              10.6
 * point            8               7.7
***********************************************/

class Solution {
public:

    // ˫ָ��
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

    // map����  
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

    // Set�洢 
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