

// 1. Brute force
// inorder -> vector to store -> sort the vector -> inorder to reorder

// 2. inorder traversal: O(n), O(h+k)
class Solution {
    TreeNode *prev = NULL, *f = NULL, *s = NULL, *t = NULL;
public:
    void dfs(TreeNode* node){
        if(node == NULL) return;
        
        dfs(node->left);
        if(prev != NULL){
            if(prev->val > node->val){
                if(f != NULL){
                    t = node;
                }
                else{
                    f = prev;
                    s = node;
                }
            }
        }
        prev = node;
        dfs(node->right);
    } 
    void recoverTree(TreeNode* root) {
        dfs(root);
        if(t == NULL){
            // swap f and s
            int tmp = f->val;
            f->val = s->val;
            s->val = tmp;
        }
        else{
            // swap f and t
            int tmp = f->val;
            f->val = t->val;
            t->val = tmp;
        }
    }
};

// Intution:
/*
	There are two cases:
	1. when nodes are adjacenty in inorder traversal
	2. when they are not adjacent
	That's why we have taken three pointers f,s,t
	for case 1, we swap f and s
	and for case 2, we swap f and t
*/