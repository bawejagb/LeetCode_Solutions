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
    int dfs(TreeNode* node, int max_val){
        if(!node) return 0;
        int cnt = 0;
        if(node->val>=max_val){
            max_val = node->val;
            cnt++;
        }
        cnt += dfs(node->left, max_val);
        cnt += dfs(node->right, max_val);
        return cnt;
    }
public:
    int goodNodes(TreeNode* root) {
        int max_val = -1e5;
        return dfs(root, max_val);
    }
};