

// 1. Comparing node's val with left and right range: O(n), O(h)
class Solution {
public:
    bool dfs(TreeNode* node, int mx, int mn){
        if(node == NULL) return true;
        
        // if node->val == INT_MIN then left subtree must be empty
        bool lf = node->val == INT_MIN ? node->left == NULL : dfs(node->left, node->val-1, mn);
        bool rt = node->val == INT_MAX ? node->right == NULL : dfs(node->right, mx, node->val+1);
    
        return lf && rt && node->val >= mn && node->val <= mx;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MAX, INT_MIN);
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

// Another template: O(n), O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        while(!st.empty() || curr){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                if(prev != NULL && prev->val >= st.top()->val) return false;
                prev = st.top();
                curr = st.top()->right;
                st.pop();
            }
        }
        return true;
    }
};