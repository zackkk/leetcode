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
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *mid = findMiddle(head);
        ListNode *right = sortList(mid->next);
        mid->next = NULL;
        ListNode *left = sortList(head);
        return mergeTwoLists(left, right);
    }
    
    ListNode *findMiddle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *newHead = new ListNode(-1); // not a build-in type, need new
        ListNode *cur = newHead;
        while(NULL != l1 || NULL != l2){
            if (NULL == l1){
                cur->next = l2;
                break;
            }
            else if (NULL == l2){
                cur->next = l1;
                break;
            }
            else{
                if(l1->val < l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                    cur = cur->next;
                }
                else{
                    cur->next = l2;
                    l2 = l2->next;
                    cur = cur->next;
                }
            }
        }
        return newHead->next;
    }
};