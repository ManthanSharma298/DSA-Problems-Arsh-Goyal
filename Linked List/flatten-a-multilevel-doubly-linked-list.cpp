/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

// Recursion: O(total number of nodes), O(number of layers)
class Solution {
public:
    Node* flat(Node* node){
        Node* p = node;

        while(true){
            if(p->child){
                Node* last = flat(p->child);    // can't be NULL
                Node* nxt = p->next;    // can be NULL

                p->next = p->child;
                p->child->prev = p;
                p->child = NULL;

                last->next = nxt;
                if(nxt) nxt->prev = last; 

                if(nxt == NULL) return last;
                p = nxt;
            }
            else{
                if(p->next == NULL) return p;
                p = p->next;
            }
        }
        return p;
    }

    Node* flatten(Node* head) {
        if(head == NULL) return NULL;
        flat(head);
        return head;
    }
};
