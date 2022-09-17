

// O(n + n) : O(n)
vector <int> maxOfMin(int arr[], int n){
    stack<int> st;
    vector<int> pre(n, 0);
    int l, r;
    for(int i=0; i<n; ++i){
        while(!st.empty() && arr[i] <= arr[st.top()]){
            int tp = st.top();
            st.pop();
            
            l = st.empty() ? -1 : st.top(), r = i;
            int ind = r-l-1;
            pre[ind-1] = max(pre[ind-1], arr[tp]);
        }
        st.push(i);
    }
    r = n;
    while(!st.empty()){
        int tp = st.top();
        st.pop();
        
        l = st.empty() ? -1 : st.top();
        int ind = r-l-1;
        pre[ind-1] = max(pre[ind-1], arr[tp]);
    }
    for(int i=n-2; i>=0; --i){
        pre[i] = max(pre[i+1], pre[i]);
    }
    return pre;
}