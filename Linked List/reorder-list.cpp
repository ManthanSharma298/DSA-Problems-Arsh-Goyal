

// find middle -> reversing second half -> inserting: O(n+n/2+n/2) ~ O(n), O(1)
class Solution {
public:
    ListNode* reverse(ListNode* node){        
        ListNode* prev = NULL, *curr = node, *nxt;
        
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
        
    }
    
    void reorderList(ListNode* head) {
        // initialising variables
        ListNode* dummy = new ListNode();
        ListNode *s = dummy, *f = dummy;
        dummy->next = head;
        
        // finding middle element by slow and fast pointers
        while(f && f->next){
            f = f->next->next;
            s = s->next;
        }
        ListNode* rev = reverse(s->next);
        s->next = NULL;
        
        // inserting rev in original list
        if(s == NULL) return;
        f = head, s = rev;
        ListNode* nxt, *snxt;
        while(s){
            nxt = f->next;
            snxt = s->next;
            
            f->next = s;
            s->next = nxt;
            
            f = nxt;
            s = snxt;
        }
    }
};