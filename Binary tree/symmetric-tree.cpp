

// DFS: O(n), O(logn)
class Solution {
public:
    bool check(TreeNode* l, TreeNode* r){
        if(l == NULL && r == NULL) return true;
        if(l == NULL || r == NULL) return false;
        
        if(l->val != r->val) return false;
        
        bool far = check(l->left, r->right);
        bool close = check(l->right, r->left);
        
        return far && close;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

// BFS: O(n), O(n)
// not pushing NULL nodes in queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        if(root->left == NULL || root->right == NULL) return false;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(q.size() >= 2){
            auto fir = q.front();
            q.pop();
            auto sec = q.front();
            q.pop();
            
            if(fir->val != sec->val) return false;
            if(fir->left == NULL && sec->right != NULL) return false;
            if(fir->left != NULL && sec->right == NULL) return false;
            if(fir->right != NULL && sec->left == NULL) return false;
            if(fir->right == NULL && sec->left != NULL) return false;

            
            if(fir->left && sec->right){
                q.push(fir->left);
                q.push(sec->right);
            }
            
            if(fir->right && sec->left){
                q.push(fir->right);
                q.push(sec->left);
            }
        }
        return q.empty();
    }
};

// Same BFS
// pushing NULL nodes in queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            auto l = st.top();
            st.pop();
            auto r = st.top();
            st.pop();
            if(l == NULL && r == NULL) continue;
            if(l == NULL || r == NULL) return false;
            if(l->val != r->val) return false;
            st.push(l->left);
            st.push(r->right);
            st.push(l->right);
            st.push(r->left);
        }
        return true;
    }
};