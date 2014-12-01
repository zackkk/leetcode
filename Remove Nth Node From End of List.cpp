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
    // slow & fast "pointers"
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while(n > 0) { fast = fast->next; n--; }
    
        if(!fast) { return head->next; } // special case
    
        while(fast->next) { slow = slow->next; fast = fast->next; }
        slow->next = slow->next->next;
        return head;
    }
};