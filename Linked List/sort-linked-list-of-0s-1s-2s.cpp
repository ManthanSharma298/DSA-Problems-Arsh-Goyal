
/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

// Counting sort: O(n+n), O(1)
Node* sortList(Node *head){
    int z=0, o=0, t=0;
    Node* p = head;

    while(p){
        if(p->data == 0) z++;
        else if(p->data == 1) o++;
        else t++;
        p = p->next;
    }
    
    p = head;
    
    while(z--){
        p->data = 0;
        p = p->next;
    }
    while(o--){
        p->data = 1;
        p = p->next;
    }
    while(t--){
        p->data = 2;
        p = p->next;
    }
    return head;
}
