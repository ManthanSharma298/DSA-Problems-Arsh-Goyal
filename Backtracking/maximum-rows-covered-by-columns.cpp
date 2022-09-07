

// O(r*c*2^c), O(c)
class Solution {
public:
    int mx;
    void rec(int i, vector<vector<int>>& m, int k){
        // base case
        if(i == m[0].size() || k == 0){
            int cnt = m.size();
            for(int x=0; x<m.size(); ++x){
                for(int y=0; y<m[0].size(); ++y){
                    if(m[x][y] == 1){
                        cnt--;
                        break;
                    }
                }
            }
            mx = max(mx, cnt);
            return;
        }
        
        // choose ith column
        vector<int> tmp;
        for(int j=0; j<m.size(); ++j){
            tmp.push_back(m[j][i]);
            if(m[j][i] == 1) m[j][i] = 0;
        }
        rec(i+1, m, k-1);
        for(int j=0; j<m.size(); ++j){
            m[j][i] = tmp[j];
        }
        // skips ith column
        rec(i+1, m, k);
        
    }
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        mx = 0;
        rec(0, matrix, numSelect);
        return mx;
    }
};