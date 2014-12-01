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
    // 1. check if we need to reverse
    // 2. reverse using prev trick
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *prev = dummy;
        ListNode *cur = head;
        while(true){
            if(listLength(cur) < k) break;
            
            ListNode *prev_future = cur;
            for(int i = 0; i < k; ++i){
                ListNode *nt = cur->next;
                ListNode *prev_nt = prev->next;
                prev->next = cur;
                cur->next = prev_nt;   
                cur = nt;   
            }
            prev_future->next = cur;
            prev = prev_future;
        }
        
        ListNode *ret = dummy->next;
        delete(dummy);
        return ret;
    }
    
    
    int listLength(ListNode *h){
        int i = 0;
        while(h){ i++; h = h->next; }
        return i;
    }
};