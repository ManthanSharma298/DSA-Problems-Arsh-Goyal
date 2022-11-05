

// O(log(max(a, b))), O(1)
// Use of unsigned int
class Solution {
public:
    int getSum(int a, int b) {
        int tmp;
        while(b != 0){
            tmp = a;
            a = a ^ b;
            b = tmp & b;
            b = (unsigned int)b << 1;
        }
        return a;
    }
}; 

// OR
class Solution {
public:
    int getSum(int a, int y) {
        int tmp;
        unsigned int b = y;
        while(b != 0){
            tmp = a;
            a = a ^ b;
            b = tmp & b;
            b = b << 1;
        }
        return a;
    }
}; 