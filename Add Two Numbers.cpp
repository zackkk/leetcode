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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        
        int carry = 0;
        while(l1 || l2){
            int sum = carry;
            if(l1) { sum += l1->val; l1 = l1->next; }
            if(l2) { sum += l2->val; l2 = l2->next; }
            ListNode *tmp = new ListNode(sum % 10);
            carry = sum / 10;
            prev->next = tmp;
            prev = tmp;
        }
        if(carry){
            ListNode *tmp = new ListNode(carry);
            prev->next = tmp;
        }
        
        ListNode *ret = dummy->next;
        delete(dummy);
        return ret;
    }
};