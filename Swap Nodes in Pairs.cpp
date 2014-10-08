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
    // consider four elements one time
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *first = head;
        ListNode *second = first->next;
        ListNode *dummy = new ListNode(-1);
        dummy->next = second;
        while(first != NULL){
            ListNode *third = second->next;
            // next 0
            if(third == NULL){
                first->next = NULL;
                second->next = first;
                break;
            }
            // next 1
            if(third->next == NULL){
                first->next = third;
                second->next = first;
                break;
            }
            // next 2
            first->next = third->next; 
            second->next = first;
            first = third;
            second = third->next;
        }
        return dummy->next;
    }
};