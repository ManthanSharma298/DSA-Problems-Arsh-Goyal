
// increasing and decreasing pattern: O(n), O(1)
bool sortArr(int n, vector<int> &arr){
    int l, r;
    if(n == 1) return true;
    int i=0;
    while(i < n-1 && arr[i] <= arr[i+1]){
        i++;
    }
  
    l = i;
    while(i < n-1 && arr[i] >= arr[i+1]){
        i++;
    }
    r = i;
    
    if(l-1 >= 0 && arr[l-1] > arr[r]) return false;
    if(r+1 < n && arr[l] > arr[r+1]) return false;
    
    for(i=r+1; i<n-1; ++i){
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}