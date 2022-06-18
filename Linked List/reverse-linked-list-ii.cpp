

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