

// bitmask + sliding window: O(n*log(num)), O(31) ~ O(1)
class Solution {
public:
    void fill(int num, vector<int>& bits){
        int i = 0;
        while(num){
            bits[i++] += num % 2;
            num /= 2;
        }
    }
    void rem(int num, vector<int>& bits){
        int i = 0;
        while(num){
            bits[i++] -= num % 2;
            num /= 2;
        }
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> bits(31, 0);
        int n = nums.size(), l = 0, r = 0, mx = 1;
        for(r=0; r<n; ++r){
            fill(nums[r], bits);
            
            int fg = 0;
            for(int bit: bits){
                if(bit > 1){
                    fg = 1;
                    break;
                }
            }
            if(fg){
                rem(nums[l], bits);
                l++;
            }
            mx = max(mx, r-l+1);
        }
        return mx;
    }
};