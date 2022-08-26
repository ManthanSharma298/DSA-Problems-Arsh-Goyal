

// inorder traversal: O(N), O(H)
class Solution{
    public: 
    Node* prev = NULL;
    Node* res;
    
    void dfs(Node* node){
        if(node == NULL) return;
        
        dfs(node->left);
        
        if(prev == NULL) res = node;
        else prev->right = node;
        node->left = prev;
        prev = node;
        
        dfs(node->right);
    }
    
    Node * bToDLL(Node *root)
    {
        dfs(root);
        return res;
    }
};