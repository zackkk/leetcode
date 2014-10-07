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
        if(head == NULL || head->next == NULL)
            return NULL;
            
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow != NULL && fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL)
                fast = fast->next;
            if(fast == slow)
                break;
        }
        if(NULL == fast)
            return NULL;
        
        // point: move "slow" back to head, then move them k steps forward
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};