

// dfs: O(n), O(h)
class Solution {
    int k;
public:
    int dfs(TreeNode* root){
        if(root == NULL) return -1;
        
        
        int l = dfs(root->left);
        if(l != -1) return l;
        k--;
        if(k == 0) return root->val;

        int r = dfs(root->right);
        if(r != -1) return r;
        return -1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        return dfs(root);
    }
};


// 2. Iteratively: O(n), O(h) 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while(!st.empty() || curr){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                auto tp = st.top();
                st.pop();
                if(k-- == 1) return tp->val; 
                curr = tp->right;
            }
        }
        return -1;
    }
};  