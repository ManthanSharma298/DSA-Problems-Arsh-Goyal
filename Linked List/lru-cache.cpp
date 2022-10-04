

// Giving TLE on both unordered_map and map
// but the approach is correct, maybe accepted after using List<int> 
class LRUCache {
public:
    class node{
    public:
        int key;
        int val;
        node* prv;
        node* nxt;
        
        node(int k, int v){
            key = k;
            val = v;
        }
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    map<int, node*> mp;
    int sz;
    
    LRUCache(int capacity) {
        sz = capacity;
        head->nxt = tail;
        tail->prv = head;
    }
    
    void add(node* root){
        node* next = head->nxt;
        
        head->nxt = root;
        root->prv = head;
        root->nxt = next;
        next->prv = root;
    }
    
    void remove(node* root){
        node* prev = root->prv;
        node* next = root->nxt;
        prev->nxt = next;
        next->prv = prev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* curr = mp[key];
            int res = curr->val;
            remove(curr);
            
            add(curr);
            mp.erase(key);
            mp[key] = head->nxt;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if key is already present then we need to modify it
        if(mp.find(key) != mp.end()){
            node* curr = mp[key];
            mp.erase(key);
            remove(curr);
        }
        // if capacity is full
        if(mp.size() == sz){
            node* rem = tail->prv;
            mp.erase(rem->key);
            remove(rem);
        }
        // simply insert it
        node* newNode = new node(key, value);
        add(newNode);
        mp[key] = head->nxt;
    }
};