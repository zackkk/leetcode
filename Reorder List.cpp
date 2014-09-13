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
    // get inserted nodes -> reverse inserted nodes -> combine two
    void reorderList(ListNode *head) {
        if(NULL == head || NULL == head->next)
            return;
        
        // get inserted nodes
        ListNode *slow = head;
        ListNode *fast = head;
        while(NULL != fast && NULL != fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur = slow->next;
        slow->next = NULL;
        
        // reverse inserted nodes
        ListNode *rightPrevHead = new ListNode(-1);
        while(NULL != cur){
            ListNode *nt = cur->next;
            cur->next = rightPrevHead->next;
            rightPrevHead->next = cur;
            cur = nt;
        }
        
        // combine two
        ListNode *left = head;
        ListNode *right = rightPrevHead->next;
        ListNode *left_nt = NULL;
        ListNode *right_nt = NULL;
        while(NULL != right){
            left_nt = left->next;
            right_nt = right->next;
            left->next = right;
            right->next = left_nt;
            left = left_nt;
            right = right_nt;
        }
    }
};