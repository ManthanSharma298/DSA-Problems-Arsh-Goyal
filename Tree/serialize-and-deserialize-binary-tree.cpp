



class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "N";
        string lf = serialize(root->left), rt = serialize(root->right);
        return to_string(root->val) + "," + lf + "," + rt;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string curr;
        for(int i = 0; i <= data.size(); ++i){
            if(i == data.size() || data[i] == ','){
                q.push(curr);
                curr = "";
            }
            else{
                curr += data[i];
            }
        }
        return decode(q);
    }
    // In class order of declaration doesn't matter 
    TreeNode* decode(queue<string>& q){
        if(q.empty()) return NULL;
        string nodeVal = q.front();
        q.pop();
        
        if(nodeVal == "N") return NULL;
        TreeNode* lf = decode(q);
        TreeNode* rt = decode(q);
        
        TreeNode* node = new TreeNode(stoi(nodeVal));
        node->left = lf;
        node->right = rt;
        
        return node;
    }
};