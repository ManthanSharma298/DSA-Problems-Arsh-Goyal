
// traversing LL: O(n), O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode();
        prev->next = head;
        
        ListNode* tmp = prev;
        ListNode* curr = head;
        
        while(curr){
            // remove this node
            if(curr->val == val){
                prev->next = curr->next;
            }
            else{
                prev = prev->next;
            }
            curr = curr->next;
        }
        return tmp->next;
    }
};