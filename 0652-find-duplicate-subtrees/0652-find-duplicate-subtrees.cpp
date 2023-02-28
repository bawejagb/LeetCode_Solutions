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
    string serializeSubtrees(TreeNode* node, unordered_map<string, int>& subtrees, vector<TreeNode*>& duplicates) {
        if (!node) return "#"; 
        string left = serializeSubtrees(node->left, subtrees, duplicates);
        string right = serializeSubtrees(node->right, subtrees, duplicates);
        string s = left + "," + right + "," + to_string(node->val); 
        if (subtrees[s] == 1) duplicates.push_back(node);
        subtrees[s]++;
        return s;
    }
 vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtrees;
        vector<TreeNode*> duplicates;
        serializeSubtrees(root, subtrees, duplicates);
        return duplicates;
    }
    
};
