/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<Node*> qt;
        qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            vector<int> lvl;
            while(size--){
                Node* temp = qt.front();
                qt.pop();
                lvl.push_back(temp->val);
                for(auto x : temp->children)
                    qt.push(x);
            }
            res.push_back(lvl);
        }
        return res;
    }
};