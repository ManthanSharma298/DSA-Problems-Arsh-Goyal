

// DFS: O(n), O(h)
class Solution {
public:
    int height(TreeNode* node){
        if(node == NULL) return 0;
        int lf, rt;
        lf = height(node->left);
        rt = height(node->right);
        if(lf == -1 || rt == -1 || abs(lf-rt) > 1) return -1;
        return max(lf, rt) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;        
    }
};