// link: https://practice.geeksforgeeks.org/contest/interview-series-61/problems/#


// k: 2360
// Prefix array: O(k + n), O(k)
class Solution {
  public:
    int minimumRooms(int n, vector<int> &start, vector<int> &end) {
        vector<int> rooms(2361, 0);
        for(int e: start){
            rooms[e]++;
        }
        for(int e: end){
            rooms[e+1]--;
        }
        
        // preffix array
        int mn = 1;
        for(int i=1; i<=2360; ++i){
            rooms[i] += rooms[i-1];
            mn = max(mn, rooms[i]);
        }
        return mn;
    }
};