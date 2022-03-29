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
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int depth=0;
        queue<TreeNode*> qt;
        TreeNode* node;
        qt.push(root);
        while(!qt.empty()){
            depth++;
            int cnt = qt.size();
            while(cnt--){
                node = qt.front();
                qt.pop();
                if(!node->left&&!node->right) return depth;
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
        }
        return depth;
    }
};