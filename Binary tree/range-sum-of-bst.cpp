

// DFS: O(n), O(logn)
class Solution {
public:
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int cnt = 0;
        if(root == NULL || low > high) return cnt;
        if(root->val >= low && root->val <= high) cnt += root->val;
        
        cnt += rangeSumBST(root->right, max(root->val, low), high);
        cnt += rangeSumBST(root->left, low, min(root->val,high));
        
        return cnt;
    }
};