

// O(1), O(1) 
class Solution {
public:
    void deleteNode(ListNode* node) {
        // if node is a tail node  NOT IN THIS QUESTION
        if(node->next == NULL) node = NULL;
        else{
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};