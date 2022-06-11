
// Using Hashing and external array: O(n+n), O(n+n)
int minSwaps(vector<int> &arr){
    int n = arr.size(), j;
    unordered_map<int, int> id;
    for(int i=0; i<n; ++i){
        id[arr[i]] = i;
    }
    
    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    int cnt=0;
    for(int i=0; i<n; ++i){
        if(arr[i] != tmp[i]){
            j = id[tmp[i]];
            id[arr[i]] = j;
            id[arr[j]] = i;
            swap(arr[i], arr[j]);
            cnt++;
        }
    }
    return cnt;
}