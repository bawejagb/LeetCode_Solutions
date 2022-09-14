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
    int freq[10]{};
    int cnt = 0;
    bool checkPalindrome(){
        int odd = 0;
        for(int i=0;i<=9;i++){
            if(freq[i]%2) odd++;
        }
        return odd < 2;
    }
    void dfs(TreeNode* node){
        if(!node) return;
        freq[node->val]++;
        if(!node->left and !node->right){
            if(checkPalindrome()) cnt++;
            freq[node->val]--;
            return;
        }
        dfs(node->left);
        dfs(node->right);
        freq[node->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return cnt;
    }
};