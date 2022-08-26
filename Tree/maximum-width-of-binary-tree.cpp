

// marking nodes by level: O(n), O(n)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        long long mx = 0;
        if(root) q.push({root, 1});
            
        while(!q.empty()){
            int n = q.size();
            long long sub = q.front().second;
            long long fst, lst;
            for(int i=0; i<n; ++i){
                auto node = q.front().first;
                long long lev = q.front().second - sub;
                q.pop();
                
                if(i == 0) fst = lev;
                if(i == n-1) lst = lev;
                
                if(node->left) q.push({node->left, 2*lev+1});
                if(node->right) q.push({node->right, 2*lev+2});
            }
            mx = max(mx, lst-fst+1);
        }
        return mx;
    }
};

/*
	i have clds 2*i+1 and 2*i+2 assuming 0 based indexing
*/