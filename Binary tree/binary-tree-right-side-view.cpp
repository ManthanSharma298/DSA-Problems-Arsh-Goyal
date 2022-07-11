

// BFS: O(n), O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root != NULL) q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; ++i){
                auto node = q.front();
                q.pop();
                
                if(i == sz-1) res.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};