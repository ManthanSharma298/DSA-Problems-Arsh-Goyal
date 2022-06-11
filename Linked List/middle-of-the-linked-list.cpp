
// Two iteration: O(n+n/2), O(1)

// fast and slow pointer: O(n), O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *s = head, *f = head;
        
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};
