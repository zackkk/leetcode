/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct mergeCmp{
    bool operator()(const ListNode &a, const ListNode &b){ // b will have higher priority
        return b.val < a.val;
    }
};
 
class Solution {
public:
    // 1. merge 2 ---> Time limit exceeded
    // 2. priority queue (min heap)
    // 3. merge sort- divide and conquer
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<int, vector<int>, mergeCmp> pq;
        for(int i = 0; i < lists.size(); i++){
            ListNode *head = lists[i];
            while(head != NULL){
                pq.push(head->val);
                head = head->next;
            }
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        while(!pq.empty()){
            int tmp = pq.top();
            pq.pop();
            ListNode *ln = new ListNode(tmp);
            prev->next = ln;
            prev = ln;
        }
        
        return dummy->next;
    }
};