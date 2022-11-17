


// insert("life")
// (l, false) -> (i, false) -> (f, false) -> (e, false) -> (empty, true)

class TrieNode {
public:
    TrieNode* node[26];
    bool isWord;
    
    TrieNode(){
        for(int i=0; i<26; ++i){
            node[i] = NULL;
        }
        isWord = false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        
        for(char c: word){
            if(curr->node[c - 'a'] == NULL){
                curr->node[c - 'a'] = new TrieNode();
            }
            curr = curr->node[c - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); ++i){
            int id = word[i] - 'a';

            if(curr->node[id] == NULL) return false;
            curr = curr->node[id];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0; i<prefix.size(); ++i){
            int id = prefix[i] - 'a';
            
            if(curr->node[id] == NULL) return false;
            
            curr = curr->node[id];
        }
        return true;
    }
};