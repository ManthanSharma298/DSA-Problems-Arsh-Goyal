

// N: number of nodes, H: height of tree -> avg(logN), worst(N)
// T.C. O(N)
// S.C. O(N + H) 

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp){
        // base condition
        if(node == NULL) return NULL;
        if(mp[node] != NULL) return mp[node];

        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        for(Node* cld: node->neighbors){
            newNode->neighbors.push_back(dfs(cld, mp));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};