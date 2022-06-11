
// Binary Search: O(n*log(sum(arr))), O(1)
bool is(vector<int>& arr,  int m, int pg){
    int req=1, curr=0;
    int i=0, n=arr.size();
    while(i < n && req <= m){
        if(curr + arr[i] <= pg){
            curr += arr[i++];
        }
        else{
            req++;
            curr = 0;
        }
    }
    if(req <= m) return true;
    return false;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int l=0, r=0, md;
    for(int e: arr) r += e;
    
    while(l+1 < r){
        md = l + (r-l)/2;
        if(is(arr, m, md)){
            r = md;
        }
        else{
            l = md;
        }
    }
    return r;
}