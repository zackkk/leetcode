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
    ListNode *partition(ListNode *head, int x) {
        if(NULL == head) return NULL;
        
        ListNode *lessHead = new ListNode(-1);
        ListNode *greaterHead = new ListNode(-1);
        
        ListNode *lessPrev = lessHead;
        ListNode *greaterPrev = greaterHead;
        
        while(NULL != head){
            ListNode *nt = head->next;
            if(head->val < x){
                lessPrev->next = head;
                lessPrev = head;
                lessPrev->next = NULL;
            }
            else{
                greaterPrev->next = head;
                greaterPrev = head;
                greaterPrev->next = NULL;
            }
            head = nt;
        }
        
        lessPrev->next = greaterHead->next;
        return lessHead->next;
    }
};