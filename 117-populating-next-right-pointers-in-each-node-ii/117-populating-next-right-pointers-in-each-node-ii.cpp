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
        if(!root) return root;
        Node* LeftMost = NULL;
        Node* prev = NULL;
        Node* rNode = root;
        while(root){
            if(root->left){
                if(!LeftMost) LeftMost = root->left;
                if(prev)  prev->next = root->left;
                root->left->next = root->right;
                prev = root->right? root->right : root->left;
            }
            else if(root->right){
                if(!LeftMost) LeftMost = root->right;
                if(prev) prev->next = root->right;
                prev = root->right;
            }
            root = root->next;
        }
        connect(LeftMost);
        return rNode;
    }
};