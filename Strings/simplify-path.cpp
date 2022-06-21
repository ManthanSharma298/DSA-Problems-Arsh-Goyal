

// 1. Using vector as stack: O(n+n), O(n)
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int i=0, n=path.size();
        while(i < n){
            if(path[i] == '/'){
                while(i+1 < n && path[i] == path[i+1] && path[i] == '/'){
                    i++;
                }
                if(path[i] == '/') i++;
                string tmp;
                while(i<n && path[i] != '/'){
                    tmp += path[i++];
                }
                
                // pushing in stack
                if(tmp != "." && tmp != ".." && tmp.size() > 0){
                    st.push_back(tmp);
                }
                else if(tmp == ".." && st.size() > 0){
                    st.pop_back();
                }
            }
        }
        string res = "/";
        for(string &s: st){
            res += s + '/';
        }
        if(res.size() > 1){
            res.pop_back();
        }
        
        return res;
    }
};

// 1.1 Same approach but clean code
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string tmp = "";
        path += '/';
        for(char &ch: path){
            if(ch == '/'){
                if(tmp == ".." && st.size() > 0){
                    st.pop_back();
                }
                else if(tmp.size() > 0 && tmp != "." && tmp != ".."){
                    st.push_back(tmp);
                }
                tmp = "";
            }
            else{
                tmp += ch;
            }
        }
        string res = "/";
        for(string &s: st){
            res += s + '/';
        }
        if(res.size() > 1){
            res.pop_back();
        }
        
        return res;
    }
}; 