

// maintianing two pointers: O(n), O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *l = dummy, *r = dummy; 
        
        while(r && r->next){
            if(r->next->val < x){
                // inserted new node
                ListNode* newNode = new ListNode(r->next->val);
                ListNode* nxt = l->next;
                l->next = newNode;
                newNode->next = nxt;

                // removed r->next node
                r->next = r->next->next;
                if(r == l) r = r->next; // Important observation
                l = l->next;
            }
            else r = r->next;
        }
        return dummy->next;
    }
};