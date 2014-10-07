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
    // 1->2->3->4->5
    // 1->3->2->4->5
    // 1->4->3->2->5
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *cur = head;
        int pos = 1; // cur pos
        
        while(pos < m){
            pos++;
            prev = prev->next;
            cur = cur->next;
        }
        
        while(pos < n && cur->next != NULL){
            pos++;
            // save all to avoid dependency mess
            ListNode *nt = cur->next;
            ListNode *nt_nt = cur->next->next;
            ListNode *prev_nt = prev->next;
            
            prev->next = nt;
            cur->next = nt_nt;
            nt->next = prev_nt;
        }
        return dummy->next;
    }
};