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
    // slow & fast
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // n will always be valid
        ListNode *slow = head;
        ListNode *fast = head;
    
        while(n > 0){
            fast = fast->next;
            n--;
        }
        // corner case: remove the first element
        if(NULL == fast)
            return head->next;
            
        ListNode *prev = NULL;
        while(NULL != fast){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};