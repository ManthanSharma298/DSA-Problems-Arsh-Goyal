

// 1. DFS in BST: O(h), O(h) 
void dfs(Node* node, Node*& pre, Node*& suc, int key){
    if(node == NULL) return;
    
    if(node->key == key){
        dfs(node->left, pre, suc, key);
        dfs(node->right, pre, suc, key);
    }
    else if(node->key < key){
        pre = node;
        dfs(node->right, pre, suc, key);
    }
    else{
        suc = node;
        dfs(node->left, pre, suc, key);
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL;
    suc = NULL;
    dfs(root, pre, suc, key);
}


// 2. Iterative: O(h), O(1)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL;
    suc = NULL;
    Node* tmp = root;

    // for pre
    while(tmp != NULL){
        if(tmp->key >= key) tmp = tmp->left;
        else{
            pre = tmp;
            tmp = tmp->right;
        }
    }
    tmp = root;
    // for suc
    while(tmp != NULL){
        if(tmp->key <= key) tmp = tmp->right;
        else{
            suc = tmp;
            tmp = tmp->left;
        }
    }
}