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
        ListNode *preHead = new ListNode(-1);
        ListNode *prev = preHead;
        
        int carry = 0;
        while(NULL != l1 || NULL != l2){
            int tmpSum = carry;
            if(NULL != l1){
                tmpSum += l1->val;
                l1 = l1->next;
            }
            if(NULL != l2){
                tmpSum += l2->val;
                l2 = l2->next;
            }
            carry = tmpSum / 10;
            ListNode *cur = new ListNode(tmpSum % 10);
            prev->next = cur;
            prev = cur;
        }
        if(0 != carry){
            ListNode *cur = new ListNode(carry);
            prev->next = cur;
        }
        return preHead->next;
    }
};