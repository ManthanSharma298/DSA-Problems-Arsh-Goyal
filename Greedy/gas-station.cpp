

// 1. Brute force: O(n*n), O(1)

// 2. Greedy approach: O(n), O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, dist, id = -1;
        
        // for Not possible case 
        for(int i=0; i<gas.size(); ++i){
            sum += gas[i] - cost[i];
        }
        if(sum < 0) return -1;
        
        sum = 0;
        for(int i=0; i<gas.size(); ++i){
            dist = gas[i] - cost[i];
            if(sum + dist >= 0){
                sum += dist;
                if(id == -1) id = i;
            }
            else{
                sum = 0;
                id = -1;
            }
        }
        return id;
    }
};

// Approach
/*
    [....][....]
    x       y
    we know that x + y >= 0 as we 
    had checked that solution exists
    we are going to start from i = 0
    and check if there exists some y
    s.t. y >= 0 then that is the answer

    AS UNIQUE SOLUTION EXISTS
*/