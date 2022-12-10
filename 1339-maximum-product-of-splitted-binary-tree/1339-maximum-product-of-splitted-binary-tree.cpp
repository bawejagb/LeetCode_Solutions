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
    vector<int> pos;
    int dfs(TreeNode* node){
        if(!node) return 0;
        int sz = pos.size();
        pos.push_back(node->val);
        pos[sz] += dfs(node->left)+dfs(node->right);
        return pos[sz];
    }
public:
    int maxProduct(TreeNode* root) {
        long res=0;
        int mod = 1e9+7;
        int total = dfs(root);
        for(int val : pos)
            res = max(res, (long)val*(total-val));
        return res%mod;
    }
};