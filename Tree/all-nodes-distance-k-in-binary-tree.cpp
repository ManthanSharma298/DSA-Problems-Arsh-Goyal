

// BFS from target node and DFS for storing parent node
// O(n+n), O(n+h+n+n)->queue, dfs, par, vis
class Solution {
    unordered_map<TreeNode*, TreeNode*> par;
public:
    void dfs(TreeNode* node){
        if(node == NULL) return;
        
        if(node->left){
            par[node->left] = node;
            dfs(node->left);
        }
        if(node->right){
            par[node->right] = node;
            dfs(node->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // fills par map
        dfs(root);
        
        queue<TreeNode*> q;
        vector<int> res;
        unordered_map<TreeNode*, int> vis;

        int level = 0;
        q.push(target);

        while(!q.empty()){
            if(level == k){
                while(!q.empty()){
                    res.push_back(q.front()->val);
                    q.pop();
                }
            }
            int sz = q.size();
            for(int i=0; i<sz; ++i){
                auto fr = q.front();
                vis[fr]++;
                q.pop();
                
                if(par.count(fr) && !vis[par[fr]]) q.push(par[fr]);
                if(fr->left && !vis[fr->left]) q.push(fr->left);
                if(fr->right && !vis[fr->right]) q.push(fr->right);
            }
            level++;
        }
        
        return res;
    }
};