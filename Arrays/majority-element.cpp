// 1. Brute force: O(n**2) O(1)

// 2. Hashmap: O(n) O(n)

// 3. Sorting: O(nlogn) O(logn) or O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};

// 4. Boyer-Moore Voting Algorithm: O(n) O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, elm = 0;
        
        for(int i=0; i<n; ++i){
            if(cnt == 0){
                elm = nums[i];
                cnt++;
            }
            else if(nums[i] == elm){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return elm;
    }
};
// worst case -> {2,2,2,1,1,1,1}
// Intution -> if we assign +1 to majority element and -1 to other elememts
//             then by adding all we get a positive number