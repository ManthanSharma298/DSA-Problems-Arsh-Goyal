

// 1. reversing and then adding: O(3*n), O(1) -> excluding output list

// 2. using two stacks: O(n+m+max(n,m)), O(n+m) -> excluding output list
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1, s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* nxt = NULL;
        int carry = 0, curr;
        while(!s1.empty() || !s2.empty() || carry > 0){
            curr = carry;
            if(!s1.empty()){
                curr += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                curr += s2.top();
                s2.pop();
            }
            
            ListNode* newNode = new ListNode(curr%10);
            carry = curr/10;
            
            newNode->next = nxt;
            nxt = newNode;
        }
        return nxt;
        
    }
};

