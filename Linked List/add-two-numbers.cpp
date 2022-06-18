

// basic addition: O(max(n,m)), O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, curr;
        ListNode* p = new ListNode();
        ListNode* tmp = p;
        while(l1 || l2 || carry){
            ListNode* newNode = new ListNode();
            curr = carry;
            if(l1){
                curr += l1->val;
                l1 = l1->next;
            }
            if(l2){
                curr += l2->val;
                l2 = l2->next;
            }
            carry = curr/10;
            newNode->val = curr%10;
            p->next = newNode;
            p = p->next;
        }
        
        return tmp->next;
    }
};