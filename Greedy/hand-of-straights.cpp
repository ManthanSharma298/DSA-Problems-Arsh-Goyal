

// 1. Multiset: O(N*logN), O(N)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int sz) {
        int n = hand.size();
        if(n % sz != 0) return false;
        multiset<int> ms;
        for(int &e: hand){
            ms.insert(e);
        }
        for(int i=0; i<n/sz; ++i){
            if(!ms.empty()){
                int val = *ms.begin();
                for(int i=0; i<sz; ++i){
                    auto it = ms.find(val + i);
                    if(it == ms.end()) return false;
                    ms.erase(it);
                }
            }
            else return false;
        }
        return true;
    }
};

// 2. same ca bee done with map also