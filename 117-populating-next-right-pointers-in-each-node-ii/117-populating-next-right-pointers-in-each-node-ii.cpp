/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> qt;
        if(!root) return root;
        qt.push(root);
        int cnt;
        Node* node;
        while(!qt.empty()){
            cnt = qt.size();
            while(cnt--){
                node = qt.front();
                qt.pop();
                if(cnt!=0) node->next = qt.front();
                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }
        }
        return root;
    }
};