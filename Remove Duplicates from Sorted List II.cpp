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
    // dummy
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *prev = dummy;
        ListNode *cur = head;
        while(cur != NULL){
            
            // found duplicates
            if(cur->next != NULL && cur->next->val == cur->val){
                while(cur->next != NULL && cur->next->val == cur->val){
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
        return dummy->next;
    }
};