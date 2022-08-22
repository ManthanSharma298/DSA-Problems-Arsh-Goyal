

// LL Traversal: O(n+n-k), O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        
        ListNode* node = head;
        int len = 1;
        while(node->next){
            len++;
            node = node->next;
        }  
        // joining the ends of LL
        node->next = head;
        k %= len;
        int cnt = len-k-1;
        node = head;
        while(cnt--){
            node = node->next;
        }
        ListNode* newHead = node->next;
        node->next = NULL;
        return newHead;
    }
};