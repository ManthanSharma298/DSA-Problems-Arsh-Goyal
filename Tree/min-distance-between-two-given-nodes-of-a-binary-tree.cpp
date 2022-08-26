

// 1. Brute force: O(n+n), O(n+h+n)
class Solution{
    Node* f, *s;
    public:
    // for finding nodes with values a and b, assigning parents to each node
    void dfs(Node* node, Node* p, int a, int b, map<Node*, Node*>& par){
        if(node == NULL) return;
        
        dfs(node->left,node,a,b,par);
        
        if(p != NULL) par[node] = p;
        if(node->data == a) f = node;
        if(node->data == b) s = node;
        
        dfs(node->right,node,a,b,par);
    }
    
    int findDist(Node* root, int a, int b) {
        // root is never equal to NULL
        map<Node*, Node*> par;
        Node* p = NULL;
        dfs(root, p, a, b, par);
    
        // applying BFS
        queue<Node*> q;
        map<Node*, int> vis;
        int dist = 0;
        q.push(f);
        vis[f]++;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; ++i){
                auto node = q.front();
                q.pop();
                
                if(node == s) return dist;
                
                if(node->left && vis[node->left] == 0){
                    q.push(node->left);
                    vis[node->left]++;
                }
                if(node->right && vis[node->right] == 0){
                    q.push(node->right);
                    vis[node->right]++;
                }
                p = par[node];
                if(p && vis[p] == 0){
                    q.push(p);
                    vis[p]++;
                }
            }
            dist++;
        }
        return dist;
    }
};


// 2. LCA + finding level of nodes: O(3*n), O(3*h) 
class Solution{
    public:
    Node* lca(Node* node, int a, int b){
        if(node == NULL) return NULL;
        
        if(node->data == a || node->data == b) return node;
        
        auto lf = lca(node->left, a, b);
        auto rt = lca(node->right, a, b);
        
        if(lf && rt) return node;
        if(lf) return lf;
        return rt;
    }
    
    int d(Node* node, int num, int lev){
        if(node == NULL) return -1;
        
        if(node->data == num) return lev;
        int lf = d(node->left, num, lev + 1);
        int rt = d(node->right, num, lev + 1);
        
        if(lf != -1) return lf;
        return rt;
    }
    
    int findDist(Node* root, int a, int b) {
        auto com = lca(root, a, b);
        int d1 = d(com, a, 0);
        int d2 = d(com, b, 0);
        
        return d1 + d2;
    }
};

// 3. can be further optimised by applying BFS to find d1 and d2: O(2*n), O(h+n)