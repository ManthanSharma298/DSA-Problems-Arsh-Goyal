

// DFS: O(n), O(h) 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        
        TreeNode* lf = lowestCommonAncestor(root->left, p, q);
        TreeNode* rt = lowestCommonAncestor(root->right, p, q);
        
        if(lf != NULL && rt != NULL) return root;
        if(lf != NULL) return lf;
        return rt;
    }
};