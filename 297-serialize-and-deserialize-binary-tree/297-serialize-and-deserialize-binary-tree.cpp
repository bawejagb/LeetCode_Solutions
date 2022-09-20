/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    //PreOrder traversal
    void preOrder(TreeNode* root, string &s){
        if(!root){
            s +="#,";
            return;
        }
        s += to_string(root->val) + ",";
        preOrder(root->left,s);
        preOrder(root->right,s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root) return s;
        preOrder(root, s);
        return s;
    }
    
    //Make Binary Tree
    TreeNode* makeTree(string data, int &index){
        if(index==data.size()) return NULL;
        int p =data.find(',',index);
        string temp = data.substr(index, p-index);
        index = p+1;
        if(temp=="#") return NULL;
        int val = stoll(temp);
        TreeNode* root = new TreeNode(val);
        root->left = makeTree(data, index);
        root->right = makeTree(data, index);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return makeTree(data, index);    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));