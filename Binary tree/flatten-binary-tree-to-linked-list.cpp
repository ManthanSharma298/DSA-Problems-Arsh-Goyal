

// 1. recursive postorder traversal: O(n), O(h)
class Solution {
    TreeNode* prev;
public:
    void dfs(TreeNode* node){
        if(node == NULL) return;
        
        TreeNode *lf = node->left, *rt = node->right;
        prev->right = node;
        prev->left = NULL;
        prev = node;
        
        dfs(lf);
        dfs(rt);
    }
    void flatten(TreeNode* root) {
        prev = new TreeNode();
        dfs(root);
    }
};

// 2. Using flatten function only: O(n*h) ~ O(n*logn), O(h)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        
        auto lf = root->left;
        auto rt = root->right;
        
        flatten(lf);
        flatten(rt);
        
        if(lf){
            root->right = lf;
            root->left = NULL;
            while(lf->right != NULL){
                lf = lf->right;
            }
            lf->right = rt;
        }
        
    }
};

// 3. Morris traversal: O(n), O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        while(root != NULL){
            if(root->left != NULL){
                auto left = root->left;
                auto curr = left;
                while(curr->right != NULL){
                    curr = curr->right;
                }
                curr->right = root->right;
                root->right = left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};