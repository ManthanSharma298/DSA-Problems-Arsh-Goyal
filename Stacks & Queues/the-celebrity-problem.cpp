

// 1. Brute force: O(N^2), O(N)
int celebrity(vector<vector<int> >& M, int n){
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(M[i][j] == 1){
                a[i]++;
                b[j]++;
            }
        }
    }
    for(int i=0; i<n; ++i){
        if(a[i] == 0 && b[i] == n-1) return i;
    }
    return -1;
}

// 2. to reduce space we can traverse through one row and then if
// 	  all elements are zero then traverse through it's column  	


// 3. Using Stack: O(N), O(N)
int celebrity(vector<vector<int> >& M, int n){
    stack<int> s;
    for(int i=0; i<n; ++i) s.push(i);
        
    while(s.size() >= 2){
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        
        if(M[i][j] == 0 && M[j][i] == 1) s.push(i);
        else if(M[i][j] == 1 && M[j][i] == 0) s.push(j);
    }   
    if(!s.empty()){
        int tp = s.top();
        // checking is must as the remaining element may be left untouched
        for(int i=0; i<n; ++i){
            if(i != tp ){
                if(M[i][tp] == 0 || M[tp][i] == 1) return -1;
            }
        }
        return tp;
    }
    else{
        return -1;
    }
}