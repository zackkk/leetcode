/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp{
    bool operator()(ListNode *a, ListNode *b){
        return b->val < a->val;
    }  
};
 
class Solution {
public:
    // min heap
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for(ListNode *ln : lists){
            if(ln)
                heap.push(ln);
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        while(!heap.empty()){
            ListNode *tmp = heap.top();
            heap.pop();
            prev->next = tmp;
            prev = tmp;
            
            if(tmp->next) heap.push(tmp->next);
        }
        
        ListNode *ret = dummy->next;
        delete(dummy);
        return ret;
    }
};