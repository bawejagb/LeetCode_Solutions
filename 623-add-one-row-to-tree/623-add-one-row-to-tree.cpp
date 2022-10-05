/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*> qt;
        qt.push(root);
        depth--;
        while(!qt.empty()){
            int size = qt.size();
            depth--;
            while(depth and size){
                size--;
                TreeNode* node = qt.front();
                qt.pop();
                if(node->left) qt.push(node->left);
                if(node->right)qt.push(node->right);
            }
            while(size > 0){
                size--;
                TreeNode* node = qt.front();
                qt.pop();
                //Left Node
                TreeNode* left = new TreeNode(val);
                left->left = node->left;
                node->left = left;
                //Right Node
                TreeNode* right = new TreeNode(val);
                right->right = node->right;
                node->right = right;
            }
        }
        return root;
    }
};