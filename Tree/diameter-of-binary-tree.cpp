

// dfs: O(n), O(logn)
class Solution {
    int mx = INT_MIN;
public:
    int dfs(TreeNode* node){
        if(node == NULL) return 0;
        int lf, rt;
        lf = dfs(node->left), rt = dfs(node->right);
        
        // ans will be max of sum of height of left and right subtrees
        mx = max(mx, lf + rt);

        // returns height of binary tree
        return max(lf, rt) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return mx;
    }
};