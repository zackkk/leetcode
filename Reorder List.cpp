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
        if(!head || !head->next) return;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur = slow->next;
        slow->next = NULL;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = cur;
        while(cur){
            ListNode *nt = cur->next;
            ListNode *dummy_nt = dummy->next;
            dummy->next = cur;
            cur->next = dummy_nt == cur ? NULL : dummy_nt;
            cur = nt;
        }
        
        ListNode *l1 = head; // longer or equal
        ListNode *l2 = dummy->next;
        while(l2){
            ListNode *l1_nt = l1->next;
            ListNode *l2_nt = l2->next;
            l1->next = l2;
            l2->next = l1_nt;
            l1 = l1_nt;
            l2 = l2_nt;
        }
        delete(dummy);
    }
};