

// 1. preffix + suffix array: O(3*n), O(2*n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n+2, 0);
        vector<int> right(n+2, 0);
        for(int i=1; i<=n; ++i){
            left[i] = max(left[i-1], height[i-1]);
        }
        for(int i=n; i>=1; --i){
            right[i] = max(right[i+1], height[i-1]);
        }
        
        int water = 0;
        for(int i=1; i<=n; ++i){
            water += max(0, min(left[i-1], right[i+1]) - height[i-1]);
        }
        return water;
    }
};



// 2. Great Intution(two pointer): O(n), O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;
        int l=0, r = n-1, lMax = height[0], rMax = height[n-1];
        
        int water = 0;
        while(l < r){
            if(lMax < rMax){
                water += lMax - height[l++];
                lMax = max(lMax, height[l]);
            }
            else{
                water += rMax - height[r--];
                rMax = max(rMax, height[r]);
            }
        }
        return water;
    }
};