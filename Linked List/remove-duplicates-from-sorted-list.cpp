
// traverse LL: O(n), O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode();
        prev->next = head;
        ListNode* res = prev;

        ListNode* curr = head;
        
        while(curr){
            if(curr != head && prev->val == curr->val){
                // delete curr node
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                curr = curr->next;
                prev = prev->next;
            }
        }
        return res->next;
    }
};