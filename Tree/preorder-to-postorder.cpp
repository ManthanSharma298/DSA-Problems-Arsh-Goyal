

// recursion: O(n), O(n+n+n)
class Solution{
public:
    Node* rec(int pre[], vector<int>& in, int pl, int pr, int il, int ir){
        if(pl > pr || il > ir) return NULL;
        Node* root = new Node();
        root->data = pre[pl];
        int i;
        for(i=il; i<=ir; ++i){
            if(in[i] == pre[pl]) break;
        }
        root->left = rec(pre, in, pl+1, pr, il, i-1);
        root->right = rec(pre, in, pl + i-il + 1, pr, i+1, ir);
        
        return root;
    }
    Node* post_order(int pre[], int size)
    {
        vector<int> in;
        for(int i=0; i<size; ++i){
            in.push_back(pre[i]);
        }
        sort(in.begin(), in.end());
        
        return rec(pre, in, 0, size-1, 0, size-1);
    }
};