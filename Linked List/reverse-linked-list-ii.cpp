

// reverse for bounded array: O(n), O(k)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr = head;
        ListNode *tmp, *start, *prev = new ListNode();
        prev->next = head;
        ListNode* res = prev;
        int cnt = 1;
        while(curr){
            if(cnt == left){
                start = prev;
            }
            if(cnt > left && cnt <= right){
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
            
            if(cnt == right){
                start->next->next = curr;
                start->next = prev;
            }
            cnt++;
        }
        return res->next;
    }
};

// Alternative solution
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp = head;
        ListNode* p = new ListNode();
        p->next = head;
        ListNode* newHead = p;
        for(int i=0; i<left-1; ++i){
            p = tmp;
            tmp = tmp->next;
        }
        
        // reversing the sublist
        int sz = right - left + 1;
        ListNode* prev = new ListNode();
        prev->next = tmp;
        ListNode* curr = tmp, *nxt;
        
        while(sz--){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        tmp->next = curr;
        p->next = prev;
        
        return newHead->next;
    }
};