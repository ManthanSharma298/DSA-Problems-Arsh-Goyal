

// Binary search: O(n*logn), O(logn)
int is(int d, int k, vector<int> &stalls){
    int c=1;
    int i=0, j=1, n=stalls.size();
    while(j < n){
        if(stalls[j] - stalls[i] >= d){
            c++;
            i = j;
        }
        j++;
    }
    return c >= k;
}
int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());
    int n=stalls.size(), l=0, r=1e9+1, m;
    while(l+1 < r){
        m = l + (r-l)/2;
        if(is(m, k, stalls)){
            l = m;    //holds answer
        }
        else{
            r = m;
        }
    } 
    return l;
}