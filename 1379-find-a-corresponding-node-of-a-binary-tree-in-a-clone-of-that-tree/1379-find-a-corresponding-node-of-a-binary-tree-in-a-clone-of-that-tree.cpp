/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(target==original) return cloned;
        TreeNode *left,*right;
        left=right=NULL;
        if(original->left) left = getTargetCopy(original->left,cloned->left,target);
        if(original->right) right = getTargetCopy(original->right,cloned->right,target);
        if(left) return left;
        return right;
        
    }
};