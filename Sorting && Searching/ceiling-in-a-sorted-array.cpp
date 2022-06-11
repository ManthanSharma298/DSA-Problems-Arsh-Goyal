
// 1. Linear Search: O(n), O(1)
int ceilingInSortedArray(int n, int x, vector<int> &arr){
    for(int i=n-1; i>=-1; --i){
        if(i == -1){
            if(i+1<n && arr[i+1] <= x) return arr[i+1];
            return -1;
        }
        if(arr[i] < x){
            if(i == n-1) return -1;
            return arr[i+1];
        }
    }
    return -1;
}

// 2. Binary Search: O(logn), O(1)
int ceilingInSortedArray(int n, int x, vector<int> &arr){
    int l=-1, r=n-1, m;
    while(l+1 < r){
        m = l + (r-l)/2;
        if(arr[m] >= x) r = m;
        else l = m;
    }
    if(arr[r] >= x) return arr[r];
    return -1;
}
