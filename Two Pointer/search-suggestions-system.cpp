
// N: products.size()
// M: searchWord.size()
// Two Pointer: O(N*logN + M+N), O(logN)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        
        int n=searchWord.size(), l=0, r=products.size()-1;
        for(int i=0; i<n; ++i){
            while(l <= r && (products[l].size() < i+1 || searchWord[i] > products[l][i])){
                l++;
            }
            while(l <= r && (products[r].size() < i+1 || searchWord[i] < products[r][i])){
                r--;
            }
            vector<string> tmp;
            for(int j = l; j <= min(r, l+2); ++j){
                tmp.push_back(products[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};