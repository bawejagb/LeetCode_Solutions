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
    int left_height(TreeNode* root){
        if(!root) return 0;
        return 1+left_height(root->left);
    }
    int right_height(TreeNode* root){
        if(!root) return 0;
        return 1+right_height(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0 ;
        int lh=left_height(root->left);
        int rh=right_height(root->right);
        if(lh==rh)
            return pow(2,lh+1)-1;
        else
            return 1+countNodes(root->left)+countNodes(root->right); 
    }
};