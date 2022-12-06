

// n: number of elements at a given time
// addNum: O(log(n/2)), O(n)
// findMedian: O(1), O(n)


class MedianFinder {
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<>> mn;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int x = mx.size(), y = mn.size();
        if(x == 0){
            mx.push(num);
        }
        // x == y+1 && x > 0, y >= 0
        else if(x == y+1){
            if(num >= mx.top()){
                mn.push(num);
            }
            else{
                mn.push(mx.top());
                mx.pop();
                mx.push(num);
            }
        }
        // x == y && x > 0
        else{
            if(num >= mx.top() && num >= mn.top()){
                mx.push(mn.top());
                mn.pop();
                mn.push(num);
            }
            else{
                mx.push(num);
            }
        }
    }
    
    double findMedian() {
        double ans;
        if(mx.size() == mn.size()){
            ans = ((double)mx.top() + (double)mn.top()) / 2;
        }
        else{
            ans = (double)mx.top();
        }
        return ans;
    }
};
