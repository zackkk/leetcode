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
        
        // create all new nodes
        RandomListNode *cur = head;
        while(NULL != cur){
            RandomListNode *newNode = new RandomListNode(cur->label); 
            mapOldToNew[cur] = newNode;
            cur = cur->next;
        }
        
        cur = head;
        while(NULL != cur){
            mapOldToNew[cur]->next = mapOldToNew[cur->next];
            mapOldToNew[cur]->random = mapOldToNew[cur->random];
            cur = cur->next;
        }
        
        return mapOldToNew[head];
    }
};