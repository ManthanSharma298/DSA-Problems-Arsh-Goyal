/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


// 1. Using Hashmap: O(n+n), O(n) ->excluding new LL
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        
        Node* tmp = head;
        while(tmp){
            Node* node = new Node(tmp->val);
            mp[tmp] = node;
            tmp = tmp->next;
        }

        tmp = head;
        while(tmp){
            auto node = mp[tmp];
            node->next = mp[tmp->next];
            node->random = mp[tmp->random];

            tmp = tmp->next;
        }

        return mp[head];
    }
};

// 2. In-place algorithm: O(n+n+n), O(1) ->excluding new LL
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Important edge case 
        if(head == NULL) return NULL;
        
        Node* tmp = head;
        Node *nxt, *rdm;
        
        // creating deep copy of nodes
        while(tmp){
            Node* node = new Node(tmp->val);
            // inserting node between tmp and nxt
            nxt = tmp->next;
            tmp->next = node;
            node->next = nxt;
            // updating tmp
            tmp = nxt;
        } 
        
        // point to random for new nodes
        tmp = head;
        while(tmp){
            rdm = tmp->random;
            if(rdm == NULL) tmp->next->random = NULL;
            else tmp->next->random = rdm->next;
            tmp = tmp->next->next;
        }

        // separate old and new nodes

        tmp = head;
        nxt = head->next;
        Node* newHead = nxt;
        
        while(tmp){
            tmp->next = tmp->next->next;
            tmp = tmp->next;
            if(nxt->next){
                nxt->next = nxt->next->next; 
                nxt = nxt->next;
            } 
        }
        return newHead;
    }
}; 