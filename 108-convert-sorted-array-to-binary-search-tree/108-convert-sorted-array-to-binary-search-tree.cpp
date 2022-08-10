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
    TreeNode* makeTree(vector<int> nums, int a, int b){
        if(a > b) return NULL;
        int mid = (a+b)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = makeTree(nums,a,mid-1);
        node->right = makeTree(nums,mid+1,b);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
            return makeTree(nums,0,nums.size()-1);
    }
};