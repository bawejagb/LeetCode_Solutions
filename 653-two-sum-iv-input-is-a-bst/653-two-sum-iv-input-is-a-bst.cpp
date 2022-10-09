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
    unordered_set<int> hmap;
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(hmap.find(1e5+(k-root->val))!=hmap.end()) return true;
        hmap.insert(1e5+root->val);
        if(findTarget(root->left, k)) return true;
        if(findTarget(root->right, k)) return true;
        return false;
    }
};