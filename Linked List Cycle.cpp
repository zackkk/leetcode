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
    // fast and slow will meet some time if there is a cycle
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow->next != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                return true;
            if(fast == NULL)
                return false;
        }
        return false;
    }
};