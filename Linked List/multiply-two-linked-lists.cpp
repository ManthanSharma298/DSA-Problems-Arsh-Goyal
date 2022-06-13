

// store in long long: O(n+m), O(1)
long long  multiplyTwoLists (Node* head1, Node* head2){
    long long n1 = 0, n2 = 0, res, mod = 1e9+7;
        
    while(head1){
        n1 = ((n1*10)%mod + head1->data)%mod;
        head1 = head1->next;
    }
    while(head2){
        n2 = ((n2*10)%mod + head2->data)%mod;
        head2 = head2->next;
    }
    
    res = (n1*n2)%mod;
    
    return res;
}