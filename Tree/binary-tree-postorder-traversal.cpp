

// Iterative: O(n), O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* tmp = root;
        
        while(tmp != NULL || !st.empty()){
            // go left
            if(tmp != NULL){
                st.push(tmp);
                tmp = tmp->left;
            }
            else{
                auto tp = st.top();
                
                if(tp->right == NULL){
                    res.push_back(tp->val);
                    st.pop();
                    while(!st.empty() && st.top()->right == tp){
                        res.push_back(st.top()->val);
                        tp = st.top();
                        st.pop();
                    }
                }
                // go right
                else{
                    tmp = tp->right;
                }
            }
        }
        
        return res;
    }
};