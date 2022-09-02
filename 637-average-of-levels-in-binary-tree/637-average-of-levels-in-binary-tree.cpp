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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        double avg;
        int count;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int size = count = qt.size();
            avg=0;
            while(size--){
                avg += qt.front()->val;
                if(qt.front()->left)
                    qt.push(qt.front()->left);
                if(qt.front()->right)
                    qt.push(qt.front()->right);
                qt.pop();
            }
            res.push_back(avg/count);
        }
        return res;
    }
};