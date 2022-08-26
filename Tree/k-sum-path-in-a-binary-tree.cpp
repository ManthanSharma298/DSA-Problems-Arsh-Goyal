

// Backtracking to store all paths: O(N*N), O(N)
vector<vector<int>> res;
// traverse through all the paths
void dfs(BinaryTreeNode<int> *node, vector<int>& tmp, int k){
    if(node == NULL) return;
    
    tmp.push_back(node->data);
    // go to left first as we need to check left part first
    dfs(node->left, tmp, k);
    dfs(node->right, tmp, k);
    
    int sum = 0;
    // traverse from back and check if sum == k
    vector<int> curr;
    for(int i=tmp.size()-1; i>=0; --i){
        sum += tmp[i];
        // curr.push_back(tmp[i]);
        
        if(sum == k){
            for(int j=i; j<tmp.size(); ++j){
                curr.push_back(tmp[j]);
            }
            res.push_back(curr);
        }
    }
    
    tmp.pop_back();
}
vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
    // Important for multiple test cases
    res.clear();
    vector<int> tmp;
    dfs(root, tmp, k);
    return res;
}
