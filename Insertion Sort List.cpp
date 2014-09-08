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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        while(NULL != head){
            ListNode *node = dummy;
            // insert "head" after "node"
            while(node->next != NULL && node->next->val < head->val){
                node = node->next;
            }
            ListNode *nt = head->next;
            head->next = node->next;
            node->next = head;
            head = nt;
        }
        return dummy->next;
    }
};