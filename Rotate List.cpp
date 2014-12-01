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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !head->next) return head;
        k = k % listLength(head);
        if(k == 0) return head;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(k > 0) { fast = fast->next; k--;}
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *ret = slow->next;
        slow->next = NULL;
        fast->next = head;
        return ret;
    }
    
    int listLength(ListNode *l){
        int i = 0;
        while(l) { i++; l = l->next; }
        return i;
    }
};