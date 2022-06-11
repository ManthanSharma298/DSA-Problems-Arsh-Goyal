// 1. Brute force: O(n**2) O(1) 

// 2. Merge sort: O(nlogn + n + n), O(n) for temp array
class Solution {
public:
    int merge(vector<int>& nums, int l, int m, int r){
        int cnt=0, i=l, j=m+1, k;
        while(i <= m){
            if(j > r){
                cnt += r-(m+1)+1;
                i++;
            }
            else if(nums[i] > 2ll*nums[j]){     // 2ll for overflow
                j++;
            }
            else{
                cnt += max(0, (j-1) - (m+1) + 1);
                i++;
            }
        }
        
        vector<int> temp(r-l+1);
        i=l, j=m+1, k=0;
        while(i <= m && j <= r){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        
        while(i <= m){
            temp[k++] = nums[i++];
        }
        while(j <= r){
            temp[k++] = nums[j++];
        }
        // update in nums array
        for(int i=0; i<temp.size(); ++i){
            nums[l+i] = temp[i];
        }
        
        return cnt;
    }
    
    int mergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return 0;
        int cnt=0, m;
        m = l + (r-l)/2;
        cnt += mergeSort(nums, l, m);
        cnt += mergeSort(nums, m+1, r);
        cnt += merge(nums, l, m, r);
        
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};