

// BFS: O(N*S*26*logN), O(N + N)
class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        queue<string> q;
        q.push(start);
        
        unordered_set<string> st;
        for(string word: wordList){
            st.insert(word);
        }
        st.erase(start);
        int lev = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; ++i){
                string s = q.front();
                q.pop();
                
                if(s == end) return lev;
                
                for(int i=0; i<s.size(); ++i){
                    char tmp = s[i];
                    for(int j=0; j<26; ++j){
                        char ch = j + 'a';
                        
                        s[i] = ch;
                        if(st.find(s) != st.end()){
                            q.push(s);
                            st.erase(s);
                        }
                        s[i] = tmp;
                    }
                }
            }
            lev++;
        }
        return 0;
    }
};