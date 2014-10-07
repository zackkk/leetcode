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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1); // not a build-in type, need new
        ListNode *cur = dummy;
        while(l1 != NULL || l2 != NULL){
            if (l1 == NULL){
                cur->next = l2;
                break;
            }
            else if (l2 == NULL){
                cur->next = l1;
                break;
            }
            else{
                if(l1->val < l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                    cur = cur->next;
                }
                else{
                    cur->next = l2;
                    l2 = l2->next;
                    cur = cur->next;
                }
            }
        }
        return dummy->next;
    }
};