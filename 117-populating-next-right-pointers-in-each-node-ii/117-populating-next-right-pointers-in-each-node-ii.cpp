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

class Solution
{
    public:
        Node* connect(Node *root)
        {
            Node *LeftMost = NULL;
            Node *prev = NULL;
            Node *rootNode = root;
            Node *parentNode = root;
            while (parentNode)
            {
                LeftMost = prev = NULL;
                root = parentNode;
                while (root)
                {
                    if (root->left)
                    {
                        if (!LeftMost) LeftMost = root->left;
                        if (prev) prev->next = root->left;
                        root->left->next = root->right;
                        prev = root->right ? root->right : root->left;
                    }
                    else if (root->right)
                    {
                        if (!LeftMost) LeftMost = root->right;
                        if (prev) prev->next = root->right;
                        prev = root->right;
                    }
                    root = root->next;
                }
                parentNode = LeftMost;
            }
            return rootNode;
        }
};