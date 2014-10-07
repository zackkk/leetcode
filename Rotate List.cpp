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
    // adjust k, slow & fast pointers
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        // adjust k
        ListNode *cur = head;
        if(getListLength(cur) == 0) return NULL;
        k = k % getListLength(cur);
        
        // fast is k stpes ahead
        while(k > 0){
            fast = fast->next;
            k--;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        // order matters, especially for case: {0}, 0
        fast->next = head;
        ListNode *dummy = slow->next;
        slow->next = NULL;
        return dummy;
    }
    
    int getListLength(ListNode *ln){
        int len = 0;
        while(ln != NULL){
            ln = ln->next;
            len++;
        }
        return len;
    }
};