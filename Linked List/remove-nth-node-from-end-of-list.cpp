

// 1. Two pass

// 2. Recursion: O(n), O(n) ->uses extra space
class Solution {
public:
    int dfs(ListNode* node, int n){
        if(node == NULL) return 0;
        
        int dnxt = dfs(node->next, n);
        if(dnxt == n){
            node->next = node->next->next;            
        }
        return dnxt + 1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        dfs(dummy, n);
        
        return dummy->next;
    }
};

// 2. One pass: O(n), O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode *l = dummy, *r = dummy;
        while(n--){
            r = r->next;
        }
        while(r->next){
            l = l->next;
            r = r->next;
        }
        
        l->next = l->next->next;
        return dummy->next;
    }
};
