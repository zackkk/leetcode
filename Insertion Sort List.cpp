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
    // maintain a sorted linked list 
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        while(head){
            ListNode *cur = dummy;
            while(cur->next && cur->next->val < head->val){
                cur = cur->next;
            }
            ListNode *nt = head->next;
            head->next = cur->next;
            cur->next = head;
            head = nt;
        }
        ListNode *ret = dummy->next;
        delete(dummy);
        return ret;
    }
};