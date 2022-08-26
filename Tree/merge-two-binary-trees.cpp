

// Tree traversal: O(n), O(logn)
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return NULL;
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        
        TreeNode* newRoot = new TreeNode(root1->val + root2->val);
        newRoot->left = mergeTrees(root1->left, root2->left);
        newRoot->right = mergeTrees(root1->right, root2->right);
        
        return newRoot;
    }
};