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
    // straight forward implementation
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            int sum = carry;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            ListNode *cur = new ListNode(sum % 10);
            prev->next = cur;
            prev = cur;
        }
        if(carry != 0){
            ListNode *cur = new ListNode(carry);
            prev->next = cur;
        }
        return dummy->next;
    }
};