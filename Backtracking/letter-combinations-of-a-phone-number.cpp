

// Brute force: O(dig.length^k), O(dig.length)
class Solution {
    unordered_map<char, vector<char>> mp;
    vector<string> res;
public:
    void rec(int i, string& curr, string& dig){
        if(i == dig.size()){
            res.push_back(curr);
            return;
        }
        for(char ch: mp[dig[i]]){
            curr.push_back(ch);
            rec(i+1, curr, dig);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        
        string curr;
        rec(0, curr, digits);
        return res;
    }
};