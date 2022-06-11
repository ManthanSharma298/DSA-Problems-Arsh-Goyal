
// Brute force: O(n**2), O(1)

// Merge sort: O(n*logn), O(n+n+n) -> id, cnt, L+R
class Solution {
    vector<int> cnt;
public:
    void merge(vector<int>& nums, vector<int>& id, int l, int r){
        int m = l + (r-l)/2;
        
        int ls=m-l+1, rs=r-m;
        vector<int> L(ls), R(rs);
        
        for(int i=0; i<ls; ++i){
            L[i] = id[i+l];
        }
        for(int i=0; i<rs; ++i){
            R[i] = id[i+m+1]; 
        }
        
        int i=0, j=0, k=l;
        
        while(i<ls && j<rs){
            if(nums[L[i]] <= nums[R[j]]){
                cnt[L[i]] += j;
                id[k++] = L[i++];
            }
            else{
                id[k++] = R[j++];
            }
        }
        
        while(i<ls){
            cnt[L[i]] += rs;
            id[k++] = L[i++];
        }
        while(j<rs){
            id[k++] = R[j++];
        }   
    }
    
    void mergeSort(vector<int>& nums, vector<int>& id, int l, int r){
        if(l >= r) return;
        int m = l + (r-l)/2;
        
        mergeSort(nums, id, l, m);
        mergeSort(nums, id, m+1, r);
        
        // merge arrays 
        merge(nums, id, l, r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        cnt.resize(n, 0);
        vector<int> id(n);
        for(int i=0; i<n; ++i){
            id[i] = i;
        }
        
        mergeSort(nums, id, 0, n-1);
        return cnt;
    }
};

