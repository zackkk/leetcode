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
    // 1. merge 2
    // 2. merge sort- divide and conquer
    // 3. priority queue (min heap)
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0) return NULL;
        ListNode *cur = lists[0];
        for(int i = 1; i < lists.size(); i++){
            cur = mergeTwoLists(cur, lists[i]);
        }
        return cur;
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