
// Traverse: O(n), O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* p = head;
        int res = 0;
        while(p){
            res = res*2 + p->val;
            p = p->next;
        }
        return res;
    }
};