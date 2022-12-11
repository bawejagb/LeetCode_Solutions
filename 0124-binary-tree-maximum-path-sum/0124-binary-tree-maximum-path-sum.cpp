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
    int ansmaxPathSum(TreeNode* root,int& maxi) {
      if(root==NULL) return 0;
      int l=max(0,ansmaxPathSum(root->left,maxi));
      int r=max(0,ansmaxPathSum(root->right,maxi));
      maxi=max(maxi,root->val+r+l);
      return root->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        ansmaxPathSum(root,ans);
        return ans;
    }
};