

// 1. Brute force
// O(n*m), O(n)
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* tmp = new ListNode();
        ListNode* head = tmp;
        
        while(a != NULL || b != NULL){
            if(a == NULL){
                tmp->next = b;
                b = b->next;
            }    
            else if(b == NULL){
                tmp->next = a;
                a = a->next;
            }
            else{
                if(a->val < b->val){
                    tmp->next = a;
                    a = a->next;
                }
                else{
                    tmp->next = b;
                    b = b->next;
                }
            }
            tmp = tmp->next;
        }
        
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        for(int i=0; i<lists.size(); ++i){
            head = merge(head, lists[i]);
        }
        return head;
    }
};


// 2. Divide and Conquer
// O(M*logN), O(logN)
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* tmp = new ListNode();
        ListNode* head = tmp;
        
        while(a != NULL || b != NULL){
            if(a == NULL){
                tmp->next = b;
                b = b->next;
            }    
            else if(b == NULL){
                tmp->next = a;
                a = a->next;
            }
            else{
                if(a->val < b->val){
                    tmp->next = a;
                    a = a->next;
                }
                else{
                    tmp->next = b;
                    b = b->next;
                }
            }
            tmp = tmp->next;
        }
        
        return head->next;
    }
    
    ListNode* divide(int l, int r, vector<ListNode*>& lists){
        if(l > r) return NULL;
        if(l == r) return lists[l];
        
        int m = l + (r-l)/2;
        ListNode* left = divide(l, m, lists);
        ListNode* right = divide(m+1, r, lists);
        
        return merge(left, right);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return divide(0, lists.size()-1, lists);
    }
};