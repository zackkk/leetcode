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
    // map old to new
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*, RandomListNode*> m;
        RandomListNode *cur = head;
        while(cur){
            RandomListNode *tmp = new RandomListNode(cur->label);
            m[cur] = tmp;
            cur = cur->next;
        }
        
        cur = head;
        while(cur){
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    }
};