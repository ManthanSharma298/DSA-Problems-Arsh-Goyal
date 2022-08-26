

// BFS: O(n): O(n+n) -> excluding result vector
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // id: level: multiset(for repeated elements)
        map<int, map<int, multiset<int>>> mp;
        queue<pair<int, TreeNode*>> q;
        // id, node
        q.push({0, root});
        
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int id = q.front().first;
                TreeNode* node = q.front().second;
                q.pop();

                mp[id][level].insert(node->val);
                if(node->left){
                    q.push({id-1, node->left});
                }
                if(node->right){
                    q.push({id+1, node->right});
                }   
            }     
            level++;
        }
        vector<vector<int>> res;
        for(auto &e: mp){
            vector<int> tmp;
            for(auto &mst: e.second){
                for(auto &num: mst.second){
                    tmp.push_back(num);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};