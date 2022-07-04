

// 1. Recursive: O(n), O(h)

// 2. Iterative: O(n), O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* tmp = root;
        
        while(tmp != NULL || !st.empty()){
            if(tmp != NULL){
                st.push(tmp);
                tmp = tmp->left;
            }
            else{
                auto tp = st.top();
                st.pop();
                res.push_back(tp->val);
                tmp = tp->right;
            }
        }
        return res;
    }
};