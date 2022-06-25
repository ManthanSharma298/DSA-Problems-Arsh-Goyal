

// Monotonic stack: O(n), O(2*n) 
class StockSpanner {
    stack<pair<int,int>> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int p = 1;
        while(!s.empty() && s.top().first <= price){
            p += s.top().second;
            s.pop();
        }
        s.push({price, p});
        return p;
    }
};