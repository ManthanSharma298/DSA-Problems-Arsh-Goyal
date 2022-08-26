

// tree traversal: O(n), O(logn) or depth of tree
class Solution {
    vector<int> nums;
public:
    TreeNode* f(int l, int r){
        if(l > r) return NULL;
        int m = l + (r-l)/2;
        
        TreeNode* node = new TreeNode(nums[m]);
        node->left = f(l, m-1);
        node->right = f(m+1, r);
        
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        return f(0, nums.size()-1);
    }
};