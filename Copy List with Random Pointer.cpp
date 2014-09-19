/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    // recursion ---> failed unknown
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, RandomListNode *> mapOldToNew;
        
        // copy nodes
        RandomListNode *cur = head;
        while(cur != NULL){
            RandomListNode *newNode = new RandomListNode(cur->label); 
            mapOldToNew[cur] = newNode;
            cur = cur->next;
        }
        
        // copy connections
        cur = head;
        while(cur != NULL){
            mapOldToNew[cur]->next = mapOldToNew[cur->next];
            mapOldToNew[cur]->random = mapOldToNew[cur->random];
            cur = cur->next;
        }
        
        return mapOldToNew[head];
    }
};