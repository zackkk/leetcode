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
    // straight-forward implementation
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *cur = head;
        while(cur != NULL){
            ListNode *nt = cur->next;
            while(nt != NULL && nt->val == cur->val)
                nt = nt->next;
            cur->next = nt;
            cur = nt;
        }
        return head;
    }
};