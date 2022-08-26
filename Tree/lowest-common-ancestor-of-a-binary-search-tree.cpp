

// 1. BST Traversal: O(logn), O(logn)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        // assuming p and q are not NULL
        int rv = root->val, pv = p->val, qv = q->val;
        if(rv == pv || rv == qv || (rv > pv && rv < qv) || (rv > qv && rv < pv)) return root;
        if(rv > pv && rv > qv) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};

// 1.1 Cleaner code 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rv = root->val, pv = p->val, qv = q->val;
        if(rv>pv && rv>qv) return lowestCommonAncestor(root->left,p,q);
        else if(rv<pv && rv<qv) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};