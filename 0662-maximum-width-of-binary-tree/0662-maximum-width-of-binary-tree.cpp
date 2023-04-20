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
    unsigned long long res;
    void dfs(TreeNode* node, vector<unsigned long long> &left, int depth, unsigned long long pos){
        if(!node) return;
        if(left[depth]==-1) left[depth]=pos;
        res = max(res, pos-left[depth]+1);
        dfs(node->left, left, depth+1, pos*2);
        dfs(node->right, left, depth+1, pos*2+1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        res = 0;
        vector<unsigned long long> left(3000,-1);
        dfs(root, left, 0, 1);
        return res;
    }
};