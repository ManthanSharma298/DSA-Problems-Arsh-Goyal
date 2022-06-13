

// by reversing half: O(1.5*n) ~ O(n), O(1)
class Solution {
public:
    ListNode* reverse(ListNode* node){
        if(node == NULL) return NULL;
        
        ListNode* prev = NULL, *curr = node, *tmp;
        while(curr){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *s = dummy, *f = dummy;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        ListNode*node = reverse(s->next);
        s = head;
        while(node){
            if(node->val != s->val) return false;
            node = node->next;
            s = s->next;
        }
        return true;
    }
};