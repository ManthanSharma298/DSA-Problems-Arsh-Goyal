

// 1. By creatingnew list: O(m+n), O(m+n)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = new ListNode();
        ListNode* tmp = p;
        
        while(list1 && list2){
            ListNode* newNode = new ListNode();
            if(list1->val <= list2->val){
                newNode->val = list1->val;
                list1 = list1->next;
            }
            else{
                newNode->val = list2->val;
                list2 = list2->next;
            }
            p->next = newNode;
            p = p->next;
        }
        while(list1){
            ListNode* newNode = new ListNode(list1->val);
            p->next = newNode;
            p = p->next;
            list1 = list1->next;
        }
        while(list2){
            ListNode* newNode = new ListNode(list2->val);
            p->next = newNode;
            p = p->next;
            list2 = list2->next;
        }
        return tmp->next;
    }
};


// 2. changing the list1: O(m+n), O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev = new ListNode();
        
        prev->next = list1;
        ListNode* newHead = prev;
        ListNode* p = list1, *q = list2;
        
        while(p && q){
            if(p->val <= q->val){
                p = p->next;
                prev = prev->next;
            }
            else{
                ListNode* tmp = q->next;
                prev->next = q;
                q->next = p;
                prev = prev->next;
                q = tmp;
            }
        }
        if(q){
            prev->next = q;
        }
        return newHead->next;
    }
};

// 3. Recursive: O(m+n), O(m+n)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list2 == NULL) return list1;
        if(list1 == NULL) return list2;
        
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }    
    }
};