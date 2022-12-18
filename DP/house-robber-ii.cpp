

// O(N + N), O(1)
class Solution {
public:
    int rec(int l, int r, vector<int>& nums){
        int pp = 0, p = 0, curr;
        for(int i=l; i<=r; ++i){
            curr = max(pp + nums[i], p);
            pp = p;
            p = curr;
        }
        return p;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(rec(0, n-2, nums), rec(1, n-1, nums));
    }
};

/*
CONCEPT USED
[-----------X], [X-----------]
first remove the last element and then calculate max money same as house robber 1
then remove the starying element and do the same thing
ans will be max of the two values
[2,----5,4] then 2 can choose 5 as array is circular i.e. 7 how to get this case
this case is repeated when we choose 5 so 2 can be chosen
*/