

// consider even index values and swap with left and right: O(n), O(1)
class Solution
{
    public:
    Node *zigZag(Node* head){
        Node *prev, *curr;
        if(head == NULL || head->next == NULL) return head;
        prev = head, curr = head->next;
        
        while(curr){
            if(prev->data > curr->data){
                int tmp = prev->data;
                prev->data = curr->data;
                curr->data = tmp;
            }
            if(curr->next){
                Node* nxt = curr->next;
                if(nxt->data > curr->data){
                    int tmp = nxt->data;
                    nxt->data = curr->data;
                    curr->data = tmp;
                }
            }
            
            if(curr->next){
                prev = prev->next->next;
                curr = curr->next->next;
            }
            else break;
        }
        return head;
    }
};