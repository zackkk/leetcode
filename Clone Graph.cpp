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
    // graph traverse: bfs and dfs
    // map: old to new

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        return bfs(node, m);
        //return dfs(node, m);
    }
    
    // bfs
    UndirectedGraphNode *bfs(UndirectedGraphNode *node, map<UndirectedGraphNode*, UndirectedGraphNode*> &m){
        if(!node) return node;
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        m[node] = copy;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        while(!q.empty()){
            UndirectedGraphNode *cur = q.front();
            q.pop();
            for(UndirectedGraphNode *neighbor : cur->neighbors){
                if(m.find(neighbor) != m.end()){
                    m[cur]->neighbors.push_back(m[neighbor]);
                }
                else{
                    q.push(neighbor);
                    UndirectedGraphNode *tmp = new UndirectedGraphNode(neighbor->label);
                    m[neighbor] = tmp;
                    m[cur]->neighbors.push_back(tmp); // where bug happened
                }
            }
        }
        return m[node];
    }
    
    
    // dfs
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, map<UndirectedGraphNode*, UndirectedGraphNode*> &m){
        if(node == NULL) return NULL;
        if(m[node]) return m[node];
        
        UndirectedGraphNode *tmp = new UndirectedGraphNode(node->label);
        m[node] = tmp;
        for(UndirectedGraphNode *neighbor : node->neighbors)
            tmp->neighbors.push_back(dfs(neighbor, m));
        return tmp;
    }
};