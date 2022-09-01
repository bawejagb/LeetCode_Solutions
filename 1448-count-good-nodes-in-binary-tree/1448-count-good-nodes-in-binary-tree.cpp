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
    int solve(TreeNode* root,int maxi){
        if(root==NULL) return 0;
        maxi=max(root->val,maxi);
        if(root->val>=maxi)
            return 1+ solve(root->left,maxi)+solve(root->right,maxi);
        return solve(root->left,maxi)+solve(root->right,maxi); 
    }
    public:
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);   
    }
};