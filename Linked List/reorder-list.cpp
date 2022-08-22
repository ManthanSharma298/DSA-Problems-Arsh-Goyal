

// 1. Brute force: O(n*n), O(1)
class Solution {
public:
    pair<ListNode*, ListNode*> lastNode(ListNode* node){
        ListNode* prev = NULL;
        while(node && node->next){
            prev = node;
            node = node->next;
        }
        return {prev, node};
    }
    void reorderList(ListNode* head) {
         // to reduce errors in LL problems write base cases
        if(head == NULL || head->next == NULL) return;

        ListNode* node = head, *nxt, *prev;
        while(node){
            auto p = lastNode(node);
            
            ListNode *prev = p.first, *last = p.second;
            if(prev == NULL || last == NULL) break;

            prev->next = NULL;
            nxt = node->next;
            node->next = last;
            last->next = nxt;

            node = nxt;
        }
    }
};

// find middle -> reversing second half -> inserting: O(n+n/2+n/2) ~ O(n), O(1)
class Solution {
public:
    // reversing second half
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL, *nxt;
        
        while(node){
            nxt = node->next;
            node->next = prev;
            prev = node;
            node = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *s = head, *f = head;

        // finding middle node
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        ListNode* a = head;
        ListNode* b = reverse(s);
        
        // arrange them
        ListNode* n1, *n2;
        while(a || b){  
            n1 = a->next;
            if(b) n2 = b->next;
            
            a->next = b;
            if(b) b->next = n1;
            
            a = n1;
            b = n2;
        }
    }
};