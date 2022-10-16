

// O(n), O(1)
int minSwaps(int arr[], int n) {
    int cnt = 0;
    for(int i=0; i<n; ++i){
        cnt += (arr[i] == 1);
    }
    if(cnt == 0) return -1;
    
    int l = 0, r = cnt-1, zr = 0;
    for(int i=l; i<=r; ++i){
        if(arr[i] == 0) zr++;
    } 
    r++;
    int mn = zr;
    while(r < n){
        if(arr[r] == 0) zr++;
        
        if(arr[l] == 0) zr--;
        l++;
        r++;
        mn = min(mn, zr);
    }
    return mn;
}