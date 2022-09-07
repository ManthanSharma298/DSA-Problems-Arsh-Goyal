

// 1. Brute force: O(n!*n)
// try all permutations

class Solution{
    public:
    string mx;
    
    bool cmp(string a, string b){
        for(int i=0; i<a.size(); ++i){
            if(a[i] == b[i]) continue;
            else if(a[i] > b[i]) return true;
            else return false;
        }
    }
    void rec(int i, string& s, int k){
        if(k == 0 || i == s.size()){   
            if(cmp(s, mx) == 1){
                mx = s;
            }
            return;
        }
        
        for(int j=i; j<s.size(); ++j){
            if(j == i){
                rec(i+1, s, k);
            }
            else{
                swap(s[i], s[j]);
                rec(i+1, s, k-1);
                swap(s[i], s[j]);
            }
        }
    }
    string findMaximumNum(string str, int k){
        mx = str;
        rec(0, str, k);
        return mx;
    }
};


// 2. You might think that it is a greedy problem
// but if we notice a number can we swapped with anyone of the 
// mx element which make it a Backtracking problem
// O(n*number_of_repeated_max)
class Solution{
    public:
    string mx;
    
    bool cmp(string a, string b){
        for(int i=0; i<a.size(); ++i){
            if(a[i] == b[i]) continue;
            else if(a[i] > b[i]) return true;
            else return false;
        }
    }
    
    void rec(int i, string& s, int k){
        if(k == 0 || i == s.size()){   
            if(cmp(s, mx) == 1){
                mx = s;
            }
            return;
        }
        char mx = s[i];
        for(int j=s.size()-1; j>i; --j){
            if(s[j] > mx){
                mx = s[j];
            }
        }
        if(mx == s[i]){
            rec(i+1, s, k);
        }
        for(int j=i+1; j<s.size(); ++j){
            if(s[j] == mx){
                swap(s[i], s[j]);
                rec(i+1, s, k-1);
                swap(s[i], s[j]);
            }
        }
    }
    
    string findMaximumNum(string str, int k){
        mx = str;
        rec(0, str, k);
        return mx;
    }
};