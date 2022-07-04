

// DFS: O(n), O(logn)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        
        bool lf = isSameTree(p->left, q->left);
        bool rt = isSameTree(p->right, q->right);
        
        return lf && rt;
    }
};