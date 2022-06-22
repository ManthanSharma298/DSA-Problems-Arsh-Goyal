

// dfs: O(n), O(logn)
class Solution {
    int mx = INT_MIN;
public:
    int dfs(TreeNode* node){
        if(node == NULL) return 0;
        int lf, rt;
        lf = dfs(node->left), rt = dfs(node->right);
        mx = max(mx, lf + rt);
        return max(lf, rt) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return mx;
    }
};