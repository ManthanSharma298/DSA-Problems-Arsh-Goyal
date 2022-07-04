

// 1. Recursive: O(n), O(h)

// 2. Iterative: O(n), O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        
        if(root != NULL) st.push(root);
        while(!st.empty()){
            auto tp = st.top();
            st.pop();
            res.push_back(tp->val);
            
            if(tp->right != NULL) st.push(tp->right);
            if(tp->left != NULL) st.push(tp->left);
        }
        
        return res;
    }
};