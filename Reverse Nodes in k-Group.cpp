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
    // 1. check if we need to reverse
    // 2. reverse using prev trick
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k <= 1) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *cur = head; // cur will move "automatically"
        
        while(cur != NULL){
            
            // check if we need to reverse
            int count = 1;
            ListNode *it = cur;
            while(it->next != NULL){ count++; it = it->next; } 
            if(count < k) break;
            
            // need to reverse
            count = 1;
            while(count < k){
                ListNode *nt = cur->next;
                cur->next = nt->next;
                nt->next = prev->next;
                prev->next = nt;
                
                count++;
            }
            prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};