

// 1. BFS: O(n), O(n)
// Not desired by the interviewer
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        
        // run bfs on tree
        if(root) q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            Node* prev = new Node();
            
            for(int i=0; i<n; ++i){
                auto node = q.front();
                q.pop();
                
                // update prev
                prev->next = node;
                prev = node;
                
                // push it's childs
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};


// 2. Recursive: O(n), O(h) 
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        
        if(root->left) root->left->next = root->right;
        if(root->next && root->right) root->right->next = root->next->left; 
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};


// 3. Iterative: O(n), O(1)
class Solution {
public:
    Node* connect(Node* root) {
        // curr traverse from starting node of a level to it's end node
        // start node is the starting node of the level
        Node *curr, *start;
        curr = root;
        start = root;

        while(curr && curr->left){
            curr->left->next = curr->right;
            if(curr->left && curr->next){
                curr->right->next = curr->next->left;
            }

            if(curr->next){
                curr = curr->next;
            }
            else{
                curr = start->left;
                start = curr;
            }
        }
        return root;
    }
};