

// by reversing half: O(n/2+n/2+n/2) ~ O(n), O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 1. finding the middle
        ListNode* s = head, *f=  head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
         
        // 2. reverse second half
        ListNode *prev = NULL, *nxt;
        while(s){
            nxt = s->next;
            s->next = prev;
            prev = s;
            s = nxt;
        }
        
        // 3. checking for palindrome
        f = head, s = prev;
        while(f && s){
            if(s->val != f->val) return false;
            s = s->next;
            f = f->next;
        }
        return true;
    }
};