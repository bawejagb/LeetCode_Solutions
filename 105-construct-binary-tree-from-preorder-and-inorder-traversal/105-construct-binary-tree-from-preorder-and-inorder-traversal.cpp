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
    int pi;


int findInd(vector<int> A, int i, int j, int val){
    
    
    for(int k=i; k<=j; k++){
        if(A[k] == val) return k;
    }
    
    return -1;
}

TreeNode* makeTree(vector<int> preorder, vector<int> inorder, int ini, int inj){
    
    if(ini > inj) return NULL;
    
    pi++;
    TreeNode* root = new TreeNode(preorder[pi]);
    int ind = findInd(inorder, ini, inj, root->val);
    
    root->left = makeTree(preorder, inorder, ini, ind-1);
    root->right = makeTree(preorder, inorder, ind+1, inj);
    
    
    return root;
    
    
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
    pi = -1;
    int ini = 0;
    int inj = inorder.size()-1;
    
    return makeTree(preorder, inorder, ini, inj);
}
};