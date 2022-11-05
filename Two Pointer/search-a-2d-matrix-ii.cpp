

// 1. Brute force: O(N*M), O(1)
// 2. Binary search row wise: O(N*logM), O(1)
// 3. Two Pointer: O(N+M), O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size(), row = 0, col = c-1;
        
        while(row < r && row >= 0 && col < c && col >= 0){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};