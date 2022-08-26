

// 1. Two dfs traversal: O(N*N), O(h*h)
class Solution {
    int cnt = 0;
    int mod = 1e9+7;    // for overflow cases
public:
    void rec(TreeNode* node, int curr, int targetSum){
        if(node == NULL) return;
        curr = (curr + node->val)%mod;
        if(curr == targetSum) cnt++;
        rec(node->left, curr, targetSum);
        rec(node->right, curr, targetSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        rec(root, 0, targetSum);
        
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        
        return cnt;
    }
};

// Intution:
/* In array we find subarray sum by two pointers in N**2 time*/


// 2. Using Hashmap same as done in array OR prefix sum: O(N), O(N)
class Solution {
    int cnt = 0, mod = 1e9+7;
    unordered_map<int,int> mp;
public:
    void rec(TreeNode* node, int curr, int target){
        if(node == NULL) return;
        
        curr = (curr + node->val)%mod;
        
        if(mp[curr-target]){
            cnt += mp[curr-target];
        }
        mp[curr]++;
        
        rec(node->left, curr, target);
        rec(node->right, curr, target);

        // remove when backtrack   
        mp[curr]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        
        mp[0] = 1;
        rec(root, 0, targetSum);
        return cnt;
    }
};