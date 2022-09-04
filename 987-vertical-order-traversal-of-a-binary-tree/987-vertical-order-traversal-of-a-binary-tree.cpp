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
    map<int,map<int,vector<int>>> res;
    void dfs(TreeNode* node, int row, int col){
        if(!node) return;
        res[col][row].push_back(node->val);
        dfs(node->left, row+1, col-1);
        dfs(node->right, row+1, col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for(auto col : res){
            vector<int> temp;
            for(auto row : col.second){
                sort(row.second.begin(), row.second.end());
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};