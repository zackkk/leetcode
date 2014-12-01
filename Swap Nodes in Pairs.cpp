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
    ListNode *swapPairs(ListNode *head) {
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *first = head;
        
        while(first){
            ListNode *second = first->next;
            if(!second){ 
                prev->next = first;
                break;
            }
            
            ListNode *third = second->next;
            
            first->next = NULL;
            second->next = first;
            prev->next = second;
            
            prev = first;
            first = third;
        }
        
        ListNode *ret = dummy->next;
        delete(dummy);
        return ret;
    }
};