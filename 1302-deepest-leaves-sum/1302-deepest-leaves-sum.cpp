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
    int depth, total;
    void dfs(TreeNode* node, int height){
        if(!node->left&& !node->right){
            if(height>depth){
                depth = height;
                total = node->val;
            }
            else if(height == depth){
                total += node->val;
            }
            return;
        }
        if(node->left) dfs(node->left, height+1);
        if(node->right) dfs(node->right, height+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        depth = total = 0;
        dfs(root, 0);
        return total;
    }
};