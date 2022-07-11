

// 1. Comparing node's val with left and right range: O(n), O(h)
class Solution {
public:
    bool check(TreeNode* node, int l, int r){
        if(node == NULL) return true;
        if(l > r) return false;
        if(node->val < l || node->val > r) return false;
        
        if(node->left && node->val == node->left->val) return false;
        if(node->right && node->val == node->right->val) return false;
        
        bool lf = node->val == INT_MIN ? check(node->left, l, INT_MIN) : check(node->left, l, node->val-1);
        bool rt = node->val == INT_MAX ? check(node->right, INT_MAX, r) : check(node->right, node->val+1, r);
        
        return lf && rt;
    }
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MIN, INT_MAX);
    }
};

// 2. Inorder traversal in BST: O(n), O(h)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        while(!st.empty() || curr != NULL){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            auto tp = st.top();
            st.pop();
            if(prev != NULL && tp->val <= prev->val) return false;
            curr = tp->right;
            prev = tp;
        }
        return true;
    }
};