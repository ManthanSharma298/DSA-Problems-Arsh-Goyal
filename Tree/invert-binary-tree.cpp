

// dfs: O(n), O(logn)
class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        TreeNode *lf = invertTree(root->left), *rt = invertTree(root->right);
        
        root->right = lf;
        root->left = rt;
        
        return root;
    }
};

// bfs: O(n),O(n)
class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            TreeNode *lf = node->left, *rt = node->right;
            
            node->left = rt;
            node->right = lf;
            
            if(lf) q.push(lf);
            if(rt) q.push(rt);
        }
        return root;
    }
};
