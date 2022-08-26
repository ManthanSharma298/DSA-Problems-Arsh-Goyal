

// Use backtracking to try all possible cases: O()
class Solution {
public:
    vector<TreeNode*> rec(int l, int r){
        vector<TreeNode*> nodes;
        if(l > r){
            nodes.push_back(NULL);
            return nodes;
        }
        // to save time
        if(l == r){
            TreeNode* root = new TreeNode(l);
            nodes.push_back(root);
            return nodes;
        }
        
        for(int i=l; i<=r; ++i){
            auto leftNodes = rec(l, i-1);
            auto rightNodes = rec(i+1, r);
            
            for(auto ln: leftNodes){
                for(auto rn: rightNodes){
                    TreeNode* root = new TreeNode(i);
                    root->left = ln;
                    root->right = rn;
                    nodes.push_back(root);
                }
            }
        }
        return nodes;
    }
    vector<TreeNode*> generateTrees(int n) {
        return rec(1, n);
    }
};