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
    // divide and conquer(merge) ---> merge sort
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next) return head;
        
        ListNode *middle = getMiddle(head);
        ListNode *left = head;
        ListNode *right = middle->next;
        middle->next = NULL;
        return mergeTwoLists(sortList(left), sortList(right));
    }
    
    ListNode *getMiddle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};