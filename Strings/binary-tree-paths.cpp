

// dfs: O(n), O(logn + n)
class Solution {
    vector<string> res;
public:
    string change(int num){
        string res = "";
        int f = 0;
        if(num < 0){
            f = 1;
            num *= -1;
        }
        while(num > 0){
            int rem = num % 10;
            res += rem + '0';
            num /= 10;
        }
        reverse(res.begin(), res.end());
        if(f) res = '-' + res;
        return res;
    }
    void dfs(string s, TreeNode* node){        
        if(node->left == NULL && node->right == NULL){
            res.push_back(s);
            return;
        }
        
        if(node->left) dfs(s + "->" + change(node->left->val), node->left);        
        if(node->right) dfs(s + "->" + change(node->right->val), node->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return res;
        string s = change(root->val);
        dfs(s, root);
        return res;
    }
}; 



// using inbuilt to_string to convert int to string 
class Solution {
    vector<string> res;
public:
    void dfs(string s, TreeNode* node){        
        if(node->left == NULL && node->right == NULL){
            res.push_back(s);
            return;
        }
        
        if(node->left) dfs(s + "->" + to_string(node->left->val), node->left);        
        if(node->right) dfs(s + "->" + to_string(node->right->val), node->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return res;
        string s = to_string(root->val);
        dfs(s, root);
        return res;
    }
}; 