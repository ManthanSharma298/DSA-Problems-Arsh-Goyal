

// DFS: O(n), O(h)
class Solution{
    int cnt = 0;
public:
    void dfs(Node* node, int l, int r){
        // base case
        if(node == NULL || l > r) return;
        if(node->data >= l && node->data <= r) cnt++;
        dfs(node->left, l, min(r, node->data-1));
        dfs(node->right, max(l, node->data), r);
    }
    int getCount(Node *root, int l, int h)
    {
        dfs(root, l, h);
        return cnt;
    }
};


// Property of BFS: O(n), O(h)
class Solution{
public:
    int getCount(Node *root, int l, int h){
    	if(root == NULL) return 0;

    	if(root->data >= l && root->data <= r){
    		return getCount(root->left, l, h) + getCount(root->right, l, r) + 1;
    	}
    	else if(root->data < l){
    		return getCount(root->right, l, h);
    	}
    	return getCount(root->left, l, h);
    }
};