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
        ListNode *cur = head;
        while(NULL != cur){
            ListNode *nt = cur->next;
            while(NULL != nt && nt->val == cur->val)
                nt = nt->next;
            cur->next = nt;
            cur = nt;
        }
        return head;
    }
};