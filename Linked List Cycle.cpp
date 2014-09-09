/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // fast and slow will meet some time if there is a cycle
    bool hasCycle(ListNode *head) {
        if(NULL == head)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(NULL != slow->next && NULL != fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
            if(NULL == fast)
                return false;
        }
        return false;
    }
};