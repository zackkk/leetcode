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
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy_a = new ListNode(-1); // less
        ListNode *dummy_b = new ListNode(-1); // greater
        ListNode *prev_a = dummy_a;
        ListNode *prev_b = dummy_b;
        
        ListNode *cur = head;
        while(cur){
            ListNode *nt = cur->next;
            if(cur->val < x){
                prev_a->next = cur;
                prev_a = cur;
            }
            else{
                prev_b->next = cur;
                prev_b = cur;
            }
            cur->next = NULL; // where bug happens
            cur = nt;
        }
        
        prev_a->next = dummy_b->next;
        
        ListNode *ret = dummy_a->next;
        delete(dummy_a);
        delete(dummy_b);
        return ret;
    }
};