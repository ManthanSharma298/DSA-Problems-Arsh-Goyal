

// DFS: O(n), O(h) -> best case: O(logn), worst case: O(n)
class Solution {
    int mn = 1e5+7;
    int prev = 1e5+7;
public:
    // inorder traversal
    int getMinimumDifference(TreeNode* node) {
        if(node == NULL) return prev;
        
        getMinimumDifference(node->left);
        mn = min(mn, abs(node->val - prev));
        prev = node->val;
        getMinimumDifference(node->right);

        return mn;
    }
};