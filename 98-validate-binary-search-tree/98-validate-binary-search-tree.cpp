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
    bool res = 1;
    long long minVal = LLONG_MIN;
    void InOrder(TreeNode* node){
        if(!node) return;
        InOrder(node->left);
        if(node->val >minVal) minVal = node->val;
        else res=0;
        InOrder(node->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        InOrder(root);
        return res;
    }
};