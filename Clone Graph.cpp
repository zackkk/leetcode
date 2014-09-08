/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // non-recursion & bfs: complicated
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(NULL == node) return NULL;
        map<UndirectedGraphNode *, UndirectedGraphNode *> mapOldToNew; // labels are unique
        return dfs(node, mapOldToNew);
    }
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, map<UndirectedGraphNode *, UndirectedGraphNode *> &mapOldToNew){ // & matters
        if(mapOldToNew[node]) 
            return mapOldToNew[node];
    
        // clone node
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        mapOldToNew[node] = newNode;
        
        // clone connections
        for(int i = 0; i < node->neighbors.size(); i++){
            newNode->neighbors.push_back(dfs(node->neighbors[i], mapOldToNew)); // need to create new
        }
        return newNode;
    }
};