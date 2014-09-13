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
        ListNode *preHead = new ListNode(-1);
        preHead->next = head;
        ListNode *prev = preHead;
        ListNode *cur = head;
        int pos = 1; // cur pos
        
        while(pos < m){
            pos++;
            prev = prev->next;
            cur = cur->next;
        }
        
        while(pos < n && NULL != cur->next){
            pos++;
            // save all to avoid dependency mess
            ListNode *nt = cur->next;
            ListNode *nt_nt = cur->next->next;
            ListNode *prev_nt = prev->next;
            
            prev->next = nt;
            cur->next = nt_nt;
            nt->next = prev_nt;
        }
        return preHead->next;
    }
};