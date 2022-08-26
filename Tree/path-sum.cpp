

// DFS: O(n), O(logn)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL && targetSum == root->val) return true;
        
        bool lf, rt;
        lf = hasPathSum(root->left, targetSum - root->val);
        rt = hasPathSum(root->right, targetSum - root->val);
        
        return lf || rt;
    }
};

