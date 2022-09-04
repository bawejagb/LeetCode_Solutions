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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            mpp[x][y].insert(node->val) ;
            if(node->left)
                q.push({node->left,{x-1,y+1}});
            if(node->right)
                q.push({node->right,{x+1,y+1}});
            q.pop();
          }
            vector<vector<int>> ans;
            for(auto p:mpp){
                vector<int> col;
                for (auto q: p.second) {
          col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
      }
      return ans;
    }
};