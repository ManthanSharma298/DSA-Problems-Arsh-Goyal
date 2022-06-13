
// swapping the pointer: O(n), O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while(p != q){
            if(p) p = p->next;
            else p = headB;
            
            if(q) q = q->next;
            else q = headA;
        }
        return p;
    }
};