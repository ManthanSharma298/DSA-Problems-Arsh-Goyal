

// DFS: O(n*m), O(logn + logm)
class Solution {
public:
    bool check(TreeNode* a, TreeNode* b){
        if(a == NULL && b == NULL) return true;
        if(a == NULL || b == NULL) return false;
        
        if(a->val != b->val) return false;
        
        bool lf = check(a->left, b->left);
        bool rt = check(a->right, b->right);
        
        return lf && rt;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;
        
        bool lf, rt, curr;
        curr = check(root, subRoot);
        if(curr) return true;
        
        lf = isSubtree(root->left, subRoot);
        rt = isSubtree(root->right, subRoot);
        
        return lf || rt;
    }
};