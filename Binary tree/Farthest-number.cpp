// link: https://practice.geeksforgeeks.org/problems/1a31d09f7b8e9c0633339df07858deb3a728fe19/1


// suffix array + bianry search: O(N*logN), O(N) -> suffix array
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> arr){
        vector<int> sf(n);
        sf[n-1] = arr[n-1];
        for(int i=n-2; i>=0; --i){
            sf[i] = min(sf[i+1], arr[i]);
        }
        
        vector<int> res(n);
        for(int i=0; i<n; ++i){
            int l = i+1, r = n;
            while(l+1 < r){
                int m = l + (r-l)/2;
                if(arr[i] > sf[m]) l = m;
                else r = m;
            }
            if(l == n || arr[l] >= arr[i]) res[i] = -1;
            else res[i] = l;
        }
        return res;
    }
};