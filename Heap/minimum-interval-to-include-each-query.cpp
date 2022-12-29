


// PQ + Sorting
// I: intervals.size(), Q: queries.size()
// O(IlogI + QlogQ + Q + Q*logI), O(logI + logQ + Q)
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){   
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> ans(queries.size(), -1);

        vector<pair<int,int>> qq;
        for(int i=0; i<queries.size(); ++i){
            qq.push_back(make_pair(queries[i], i));
        }
        sort(qq.begin(), qq.end());
        int i=0;
        for(auto &e: qq){ 
            int q = e.first;
            while(i < intervals.size()){
                if(q >= intervals[i][0]){
                    pq.push(make_pair(intervals[i][1]-intervals[i][0]+1, intervals[i][1]));
                    i++;
                }
                else{
                    break;
                }
            }
            while(!pq.empty()){
                auto tp = pq.top();
                if(q <= tp.second){
                    ans[e.second] = tp.first;
                    break;
                }
                else{
                    pq.pop();
                }
            }
        }
        return ans;
    }   
};