

// delete continuous part: O(n+n), O(1)
class Solution {
public:
    void del(ListNode *&prev, ListNode *&l, ListNode *&r){
        while(prev->next != r){
            prev->next = prev->next->next;
        }
        l = r;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* d = new ListNode();
        d->next = head;

        ListNode *prev = d, *l = head, *r = head;
        int cnt = 0;
        while(r){
            if(l->val == r->val){
                r = r->next;
                cnt++;
            }
            else if(cnt > 1){
                del(prev, l, r);
                cnt = 0;
            }
            else{
                r = r->next;
                l = l->next;
                prev = prev->next;
            }
        }
        if(cnt > 1){
            del(prev, l, r);
        }
        return d->next;
    }
};