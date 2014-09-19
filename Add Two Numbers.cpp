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
            int tmpSum = carry;
            if(l1 != NULL){
                tmpSum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                tmpSum += l2->val;
                l2 = l2->next;
            }
            carry = tmpSum / 10;
            ListNode *cur = new ListNode(tmpSum % 10);
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