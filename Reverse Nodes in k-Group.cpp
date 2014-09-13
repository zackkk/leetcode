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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k <= 1) return head;
        ListNode *prev_head = new ListNode(-1);
        prev_head->next = head;
        
        ListNode *prev = prev_head;
        ListNode *cur = head; // cur will move "automatically"
        while(NULL != cur){
            // check if we need to reverse
            int count = 1;
            ListNode *it = cur;
            while(NULL != it->next){ count++; it = it->next; } 
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
        return prev_head->next;
    }
};