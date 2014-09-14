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
        if(NULL == head || NULL == head->next)
            return head;
        ListNode *first = head;
        ListNode *second = first->next;
        ListNode *newHead = new ListNode(-1);
        newHead->next = second;
        while(NULL != first){
            ListNode *third = second->next;
            // next 0
            if(NULL == third){
                first->next = NULL;
                second->next = first;
                break;
            }
            // next 1
            if(NULL == third->next){
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
        return newHead->next;
    }
};