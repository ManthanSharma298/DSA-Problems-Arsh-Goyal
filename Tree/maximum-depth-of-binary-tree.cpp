

// Recursive: O(n), O(logn)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};      

// Iterative: O(n), O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        
        if(root) q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; ++i){
                TreeNode* fr = q.front();
                q.pop();
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }
            level++;
        }
        return level;
    }
};                                                                                           