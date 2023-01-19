

// Binary Search + Sliding Window: O(N*logN), O(1)
class Solution {
public:
    bool isValid(vector<int>& fq, int k){
        return fq[0] >= k && fq[1] >= k && fq[2] >= k;
    } 
    int takeCharacters(string s, int k) {
        int n = s.size(), l = 3*k, r = n, ans = n, m;
        vector<int> fq(3, 0);
        for(char &c: s){
            fq[c - 'a']++;
        }
        if(!isValid(fq, k)) return -1;
        while(l <= r){
            m = l + (r-l)/2;
            int lf = m-1, rt = n-1, fg = 0;
            for(int &e: fq) e = 0;
            for(int i=0; i<m; ++i) fq[s[i] - 'a']++;
            if(isValid(fq, k)){
                fg = 1;
            }
            else{
                while(lf >= 0){
                    fq[s[lf] - 'a']--;
                    fq[s[rt] - 'a']++;
                    if(isValid(fq, k)){
                        fg = 1;
                        break;
                    }
                    lf--;
                    rt--;
                }
            }
            if(fg){
                r = m-1;
                ans = min(ans, m);
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};