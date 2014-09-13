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
    // slow & fast, adjust k
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        // adjust k
        ListNode *cur = head;
        int len = 0;
        while(NULL != cur){
            cur = cur->next;
            len++;
        }
        if(len == 0) return NULL;
        k = k % len;
        
        // fast is k stpes ahead
        while(k > 0){
            fast = fast->next;
            k--;
        }
        while(NULL != fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        // order matters, especially for case: {0}, 0
        fast->next = head;
        ListNode *newHead = slow->next;
        slow->next = NULL;
        return newHead;
    }
};