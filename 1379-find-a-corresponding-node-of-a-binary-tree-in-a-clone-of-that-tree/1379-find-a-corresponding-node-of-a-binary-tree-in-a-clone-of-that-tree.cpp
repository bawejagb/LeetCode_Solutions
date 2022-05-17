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
        if(original==NULL) return NULL;
        if(original == target) return cloned;
        TreeNode* lt = getTargetCopy(original->left, cloned->left, target);
        TreeNode* rt = getTargetCopy(original->right, cloned->right, target);
        if(lt) return lt;
        else return rt;
    }
};