

// O(n), O(n) -> excluding preorder & postorder
class Solution {
public:
    TreeNode* rec(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd){
        if(preStart > preEnd || postStart > postEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        // big mistake: preStart+1 == n-1 but n is not the last node so do this instead
        // only single node is present
        if(preStart == preEnd) return root;
        
        int i;
        for(i=postStart; i<=postEnd; ++i){
            if(postorder[i] == preorder[preStart+1]) break;
        }
        
        root->left = rec(preorder, postorder, preStart+1, preStart+1 + i-postStart, postStart, i);
        root->right = rec(preorder, postorder, preStart+1 + i-postStart+1, preEnd, i+1, postEnd-1);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return rec(preorder, postorder, 0, n-1, 0, n-1);
    }
};