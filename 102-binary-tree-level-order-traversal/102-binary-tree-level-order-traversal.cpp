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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            TreeNode* node;
            int sz = qt.size();
            vector<int> temp;
            while(sz--){
                node = qt.front();
                qt.pop();
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
                temp.push_back(node->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};