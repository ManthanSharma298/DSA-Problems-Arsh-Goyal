

// Using Linked List: O(1) average time and O(h) memory
class BSTIterator {
public:
    class Node{
    public:
        Node* next; 
        int val;
        Node(){
            val = 0;
            next = NULL;
        }
        Node(int val){
            this->val = val;
            next = NULL;
        }
    };

    Node* prev;
    Node* head;
    
    BSTIterator(TreeNode* root) {
        // we know root is not NULL
        prev = new Node();        
        head = prev;
        dfs(root);
        head = head->next;
    }
    
    // inorder traversal
    void dfs(TreeNode* root){
        if(root == NULL) return;
        dfs(root->left);
        Node* node = new Node(root->val);
    
        // adding new node
        prev->next = node;
        prev = node;
        
        dfs(root->right);
    }
    int next() {
        int res = head->val;
        head = head->next;
        return res;
    }
    
    bool hasNext() {
        return head != NULL;
    }
};

// 2. Using Stack: O(1) average time and O(h) memory
class BSTIterator {
    stack<TreeNode*> s;
public:
    void left(TreeNode* node){
        while(node){
            s.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        left(root);
    }
    
    int next() {
        auto tp = s.top();
        s.pop();
        left(tp->right);
        return tp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};