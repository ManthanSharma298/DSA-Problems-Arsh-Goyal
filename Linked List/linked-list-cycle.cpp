
// fast and slow pointer: O(n), O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* f = head, *s = head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
            if(s == f) return true;
        }
        return false;
    }
};