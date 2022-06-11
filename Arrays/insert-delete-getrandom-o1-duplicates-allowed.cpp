
// Using map,set,vector: 
// insert: O(logn) avg time O(1)
// remove: O(logn) avg time O(1)
// random: O(1)

class RandomizedCollection {
    map<int,set<int>> id;
    vector<int> data;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool res = false;
        if(id[val].size() == 0) res = true;
        
        data.push_back(val);
        id[val].insert(data.size()-1);
        
        return res;
    }
    
    bool remove(int val) {
        if(id[val].size() == 0) return false;
        
        auto itr = id[val].begin();
        int idx = *itr;
        id[val].erase(itr); // DELETE AFTER GETTING IDX AS *itr IS A POINTER 

        data[idx] = data[data.size()-1];
        
        // if idx == data.size()-1 then we need to remove the element completely
        // and don't need to update the index of last element
        if(idx != data.size()-1){
            //Update last index entry in set
            id[data[idx]].erase(data.size()-1);
            id[data[idx]].insert(idx);
        }
        data.pop_back();
        
        return true;
    }
    
    int getRandom() {
        if(data.size() == 0) return -1;
        
        int rid = rand() % data.size();
        return data[rid];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

