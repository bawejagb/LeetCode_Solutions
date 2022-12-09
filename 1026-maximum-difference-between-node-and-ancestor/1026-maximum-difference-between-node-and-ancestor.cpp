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
    void dfs(TreeNode* node, int minVal, int maxVal, int &res){
        if(!node){
            res = max(res, maxVal-minVal);
            return;
        }
        minVal = min(minVal,node->val);
        maxVal = max(maxVal, node->val);
        dfs(node->left,minVal, maxVal,res);
        dfs(node->right,minVal, maxVal,res);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int res=0;
        dfs(root, root->val, root->val,res);
        return res;
    }
};