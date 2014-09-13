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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *prev_head = new ListNode(-1);
        prev_head->next = head;
        
        ListNode *prev = prev_head;
        ListNode *cur = head;
        while(NULL != cur){
            // delete duplicates
            if(NULL != cur->next && cur->next->val == cur->val){
                while(NULL != cur->next && cur->next->val == cur->val){
                    cur = cur->next;
                }
                cur = cur->next;
                prev->next = cur;
            }
            else{
                //prev->next = cur;
                prev = cur;
                cur = cur->next;
            }
        }
        return prev_head->next;
    }
};