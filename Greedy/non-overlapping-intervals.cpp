

// Sorting & Interval: O(n*logn + n), O(logn)
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        int cnt = 0, end = intervals[0][1];
        for(int i=1; i<intervals.size(); ++i){
            int cs = intervals[i][0], ce = intervals[i][1];
            if(cs < end){
                cnt++;
                end = min(end, ce);
            }
            else{
                end = ce;
            }
        }
        return cnt;
    }
};