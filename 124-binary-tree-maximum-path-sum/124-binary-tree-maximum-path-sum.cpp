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
    int min_val = -1e8;
    int res= min_val;
    int dfs(TreeNode* root){
        if(!root) return min_val;
        int val = root->val;
        int left_val,right_val;
        left_val = dfs(root->left);
        right_val = dfs(root->right);
        res = max({res,left_val+val,right_val+val,val,min_val,left_val+right_val+val});
        return max({left_val+val,right_val+val,val,min_val});
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};