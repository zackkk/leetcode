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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int lenA = 0;
        int lenB = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while(curA){ lenA++; curA = curA->next; }
        while(curB){ lenB++; curB = curB->next; }
        
        curA = headA;
        curB = headB;
        int diff = abs(lenA - lenB);
        if(lenA > lenB){ 
            while(diff > 0) { diff--; curA = curA->next; }
        }
        else {
            while(diff > 0) { diff--; curB = curB->next; }
        }
        
        int len = min(lenA, lenB);
        while(len > 0 && curA != curB){
            len--;
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};