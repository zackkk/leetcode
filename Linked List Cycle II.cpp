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
    // x = k + t 
    // y = k + t + c
    // y = 2x ---> k + t = c ---> move meet pointer k steps forward
    ListNode *detectCycle(ListNode *head) {
        if(NULL == head || NULL == head->next)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while(NULL != slow && NULL != fast){
            slow = slow->next;
            fast = fast->next;
            if(NULL != fast)
                fast = fast->next;
            if(slow == fast)
                break;
        }
        if(NULL == fast)
            return NULL;
        
        // move meet pointer k steps forward
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};