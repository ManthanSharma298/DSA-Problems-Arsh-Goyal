

// O(n), O(height)
class Solution {
    int mx = INT_MIN;
public:
    int helper(TreeNode* root){
        if(root == NULL) return 0;
        
        int lMax = helper(root->left);
        int rMax = helper(root->right);
        
        // consider all cases like to include left, right or not
        mx = max({mx, lMax + rMax + root->val, lMax+root->val, rMax+root->val, root->val});
        // we need to return root 
        return max({lMax, rMax, 0}) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return mx;
    }
};


// Clean solution 
class Solution {
    int res = -1e9;
public:
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int lf = dfs(root->left), rt = dfs(root->right);

        // a better approach: making the negative child zero will reduce the effect in left + root + right
        // which will cover all the above cases
        if(lf < 0) lf = 0;
        if(rt < 0) rt = 0;
        
        res = max(res, lf + rt + root->val);
        return max(lf, rt) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};