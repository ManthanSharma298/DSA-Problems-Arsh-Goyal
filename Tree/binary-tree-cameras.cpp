

// O(N), O(N)
class Solution {
public:
    // tree contain only three type of nodes
    // 0: not been tracked
    // 1. been tracked from either parent or child node
    // 2. have camera
    // -1 for NULL node
    
    int cnt = 0;
    TreeNode* top;
    int dfs(TreeNode* node){
        // to not add camera to leaf nodes
        if(node == NULL) return -1;
        
        int lf = dfs(node->left), rt = dfs(node->right);
        if(lf == 0 || rt == 0){ 
            cnt++;
            return 2;
        }
        if(lf == 2 || rt == 2) return 1;
        // if node is the root node and child don't have camera installed
        if(node == top){
            cnt++;
            return 2;
        }
        return 0;
        
    }
    int minCameraCover(TreeNode* root) {
        top = root;
        dfs(root);
        return cnt;
    }
};