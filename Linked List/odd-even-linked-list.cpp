

// LL Traversal: O(n), O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *odd = head, *even = head->next, *tmp = even;
        while(even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            
            odd = odd->next;
            even = even->next;
        }
        odd->next = tmp;
        return head;
    }
};