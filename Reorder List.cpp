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
    // 1. cut into halfs 
    // 2. reverse insert nodes 
    // 3. combine two
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return;
        
        // cut into halfs 
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur = slow->next;
        slow->next = NULL;
        
        // reverse insert nodes
        ListNode *rightPrevHead = new ListNode(-1);
        while(cur != NULL){
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
        while(right != NULL){
            left_nt = left->next;
            right_nt = right->next;
            left->next = right;
            right->next = left_nt;
            left = left_nt;
            right = right_nt;
        }
    }
};