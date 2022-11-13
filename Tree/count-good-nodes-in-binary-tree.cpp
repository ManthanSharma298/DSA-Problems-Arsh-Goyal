


// O(N), O(logN)
class Solution {
public:
    int dfs(TreeNode* par, TreeNode* curr){
        if(curr == NULL) return 0;
        int ans = 0;
        TreeNode* mx;
        if(par == NULL || curr->val >= par->val){
            ans++;
            mx = curr;
        }
        else{
            mx = par;
        }
        ans += dfs(mx, curr->left);
        ans += dfs(mx, curr->right);
        return ans;
    }
    int goodNodes(TreeNode* root) {
        return dfs(NULL, root);
    }
};