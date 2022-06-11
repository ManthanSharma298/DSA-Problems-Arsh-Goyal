

// Binary Search: O(n*logn), O(logn)
bool findPair(int arr[], int size, int n){
    sort(arr, arr+size);
    for(int i=1; i<size; ++i){
        int target = arr[i] - n;
        if(target <= 0) continue;
        int l=0, r=i, m;
        while(l+1 < r){
            m = l + (r-l)/2;
            if(arr[m] > target) r = m;
            else l = m;
        }
        if(arr[l] == target) return true;
    }
    return false;
}

// Using set: O(n), O(n)
bool findPair(int arr[], int size, int n){
    unordered_set<int> s;
    for(int i=0; i<size; ++i){
        if(s.count(arr[i] - n) || s.count(arr[i] + n)) return true;
        s.insert(arr[i]);
    }
    return false;
}