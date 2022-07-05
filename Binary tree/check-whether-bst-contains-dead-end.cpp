

// BST Range Traversal: O(n), O(h)
bool dfs(int l, int r, Node* node){
    if(node == NULL) return false;
    
    if(l == r) return true;
    bool lf = dfs(l, node->data-1, node->left);
    bool rt = dfs(node->data+1, r, node->right);
    
    return lf || rt;
}
/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    return dfs(1, 1e9, root);
}

