


// Time complx: O(4^(r*c))
// We have atmost four choices at a time
// so whatever decision we made we have to traverse through whole r*c matrix

// Space complx: O(r*c) res matrix

bool isVal(int i, int j, vector<vector<int>> &m, int n){
    if(i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0 || m[i][j] == -1) return false;
    return true;
}
void rec(int i, int j, string& s, vector<vector<int>> &m, int n){
    if(i == n-1 && j == n-1){
        res.push_back(s);
        return;
    }
    m[i][j] = -1;
    if(isVal(i+1,j,m,n)){
        s += 'D';
        rec(i+1,j,s,m,n);
        s.pop_back();
    }
    if(isVal(i,j-1,m,n)){
        s += 'L';
        rec(i,j-1,s,m,n);
        s.pop_back();
    }
    if(isVal(i,j+1,m,n)){
        s += 'R';
        rec(i,j+1,s,m,n);
        s.pop_back();
    }
    if(isVal(i-1,j,m,n)){
        s += 'U';
        rec(i-1,j,s,m,n);
        s.pop_back();
    }
    m[i][j] = 1;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    string s = "";
    if(m[0][0] == 0) return res;
    rec(0,0,s,m,n);
    return res;
}
