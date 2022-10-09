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
    void inOrder(TreeNode* node, vector<int> &vec){
        if(!node) return;
        inOrder(node->left, vec);
        vec.push_back(node->val);
        inOrder(node->right, vec);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inOrder(root, vec);
        int i=0, j = vec.size()-1;
        while(i<j){
            if(vec[i]+vec[j]==k) return true;
            if(vec[i]+vec[j]<k) i++;
            else j--;
        }
        return false;
    }
    
};