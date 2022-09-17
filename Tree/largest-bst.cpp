

// dfs: O(N), O(H)
class Solution{
    public:
    // returns {smallest, largest, size}
    vector<int> check(Node* node){
        if(node == NULL) return {INT_MAX, INT_MIN, 0};
        
        auto l = check(node->left);
        auto r = check(node->right);
        
        
        if(l[1] < node->data && r[0] > node->data){
            return {min(l[0], node->data), max(r[1], node->data), l[2] + r[2] + 1};
        }
        return {INT_MIN, INT_MAX, max(l[2], r[2])};
        
    }
    int largestBst(Node *root){
        return check(root)[2];
    }
};