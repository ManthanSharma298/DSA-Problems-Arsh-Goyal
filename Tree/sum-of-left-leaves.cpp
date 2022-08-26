

// DFS: O(n), O(h)
// using flag
class Solution {
    int fg = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        
        if(root->left == NULL && root->right == NULL && fg) return root->val;
        fg = 1;
        int lf = sumOfLeftLeaves(root->left);
        fg = 0;
        int rt = sumOfLeftLeaves(root->right);
        
        return lf + rt;
    }
};

// without using flag
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        // if left node is leaf node
        int curr = 0;
        if(root->left){
            if(root->left->left == NULL && root->left->right == NULL) curr += root->left->val;
        }
        curr += sumOfLeftLeaves(root->left);
        curr +=  sumOfLeftLeaves(root->right);
        
        return curr;
    }
};