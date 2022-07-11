

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


// 1. Recursion: O(number of integers in nestedList), O(max number of nested lists)
class NestedIterator {
    vector<int> res;
    int i, sz;
public: 
    void rec(vector<NestedInteger> &list){
        for(int i=0; i<list.size(); ++i){
            if(list[i].isInteger()){
                res.push_back(list[i].getInteger());
            }  
            else{
                rec(list[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        rec(nestedList);
        i = 0;
        sz = res.size();
    }
    
    int next() {
        if(i < sz) return res[i++];
        return INT_MIN;
    }
    
    bool hasNext() {
        return i < sz;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
