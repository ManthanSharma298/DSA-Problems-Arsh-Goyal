// 1. Brute force: O(n**2) O(1)
// 2. negative marking: O(n) O(1) but modifies the array
// 3. Hashmap, array, set: O(n) O(n) use extra memory


// 4. Binary search: O(nlogn) O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(),l=0, r=n-1,m,cnt;
        while(l+1 < r){
            m = l + (r-l)/2;
            cnt=0;
            for(int num: nums){
                if(num <= m) cnt++;
            }
            
            if(cnt > m) r = m;  // stores possible answer
            else l = m;
        }
        return r;
    } 
};


// 5. fast-slow pointer O(n) O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int f=nums[0],s=nums[0],st=0;
        while(f != s || st == 0){
            f = nums[nums[f]];
            s = nums[s]; 
            st++;
        }
        
        // nums[f] == nums[s]
        f = nums[0];
        while(f != s){
            f = nums[f];
            s = nums[s];
        }
        return f;
    } 
};