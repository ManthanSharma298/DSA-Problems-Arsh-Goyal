
// Using map: O(1), O(k) -> where k is a constant
class Solution {
public:
    int dist(vector<int> a, vector<int> b){
        int res;
        res = (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
        return res;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int a = dist(p1, p2);
        int b = dist(p1, p3);
        int c = dist(p1, p4);
        int d = dist(p2, p3);
        int e = dist(p2, p4);
        int f = dist(p3, p4);
        
        map<int,int> mp;
        mp[a]++; mp[b]++; mp[c]++; mp[d]++; mp[e]++; mp[f]++;
        
        if(mp.size() != 2) return false;
        auto itr = mp.begin();
        int d1 = itr->first, c1 = itr->second;
        itr++;
        int d2 = itr->first, c2 = itr->second;
        
        if(c1 == 4 && c2 == 2 && d2 == 2*d1) return true;
        return false;
    }
};