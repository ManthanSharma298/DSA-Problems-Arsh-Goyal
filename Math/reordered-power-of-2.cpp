

// compare digits of all power of two: O(30*logn*10), O(30*n)
class Solution {
public:
    bool cmp(vector<int>& a, vector<int>& b){
        for(int i=0; i<10; ++i){
            if(a[i] != b[i]) return false;
        }   
        return true;
    }
    
    vector<int> count(int num){
        vector<int> res(10, 0);
        while(num){
            res[num % 10]++;
            num /= 10;
        }
        return res; 
    }
    bool reorderedPowerOf2(int n) {
        vector<int> curr = count(n);
        
        int twoPower = 1;
        for(int i=0; i<30; ++i){
            vector<int> tmp = count(twoPower);
            if(cmp(curr, tmp)) return true;
            twoPower *= 2;
        }
        return false;
    }
};