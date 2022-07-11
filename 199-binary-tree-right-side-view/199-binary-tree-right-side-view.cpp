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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL){return res;}
        int max = -1;
        vector<pair<TreeNode*, int>> temp;
        temp.push_back(make_pair(root, 0));
        while(temp.empty() == false)
        {
            auto pair = temp.back();
            temp.pop_back();
            if(max < pair.second){res.push_back(pair.first->val); max = pair.second;}
            if(pair.first->left) {temp.push_back(make_pair(pair.first->left, pair.second+1));}
            if(pair.first->right) {temp.push_back(make_pair(pair.first->right, pair.second+1));}
        }
        return res;
    }
};