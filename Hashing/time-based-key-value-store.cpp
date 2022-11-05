

// Hashing + Binary Search
// set: O(1)
// get: O(logM) 
// Time complexity: O(N)

// COMMON MISTAKES: DON'T COPY MP[KEY] TO A VECTOR, IT'LL GIVE TLE		
class TimeMap {
public:
    class data{
        public:
        int timestamp;
        string value;
        
        data(int timestamp, string value){
            this->timestamp = timestamp;
            this->value = value;
        }
    };
    unordered_map<string, vector<data>> mp;
    TimeMap() {
        
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back(data(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }
        int m, l = 0, r = mp[key].size();
        while(l+1 < r){
            m = l + (r-l)/2;
            if(mp[key][m].timestamp <= timestamp){
                l = m;
            }
            else{
                r = m;
            }
        }
        if(mp[key][l].timestamp <= timestamp) return mp[key][l].value;
        return "";
    }
};
