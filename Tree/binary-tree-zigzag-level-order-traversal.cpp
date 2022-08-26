

// 1. storing in revserse order in vector: O(n), O(n) -> excluding vector
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> layer;
        if(root) q.push(root);
        
        int fg = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> tmp(n);
            for(int i=0; i<n; ++i){
                auto node = q.front();
                q.pop();
                
                if(fg) tmp[n-i-1] = node->val;
                else tmp[i] = node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            fg = (fg+1)%2;
            layer.push_back(tmp);
        }
        return layer;
    }
};


// 2. Using Deque: O(n), O(n)
// This is the required solution
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        vector<vector<int>> res;
        
        if(root) dq.push_back(root);
        int fg = 0; // from left to right
        while(!dq.empty()){
            int n = dq.size();
            vector<int> tmp;
            for(int i=0; i<n; ++i){
                if(fg == 0){
                    auto node = dq.front();
                    dq.pop_front();
                    
                    tmp.push_back(node->val);
                    
                    if(node->left) dq.push_back(node->left);
                    if(node->right) dq.push_back(node->right);
                }
                else{
                    auto node = dq.back();
                    dq.pop_back();
                    
                    tmp.push_back(node->val);
                    
                    if(node->right) dq.push_front(node->right);
                    if(node->left) dq.push_front(node->left);
                }
            }
            res.push_back(tmp);
            fg ^= 1;
        }
        return res;
    }
};