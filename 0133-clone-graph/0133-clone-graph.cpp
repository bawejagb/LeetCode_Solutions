/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int,Node*> hmap;
    Node* dfs(Node* node, Node* cnode){
        if(node==NULL) return node;
            cnode = new Node();
            cnode->val = node->val;
        hmap[cnode->val] = cnode;
        for(auto c : node->neighbors){
            if(hmap.find(c->val)!=hmap.end()){
                cnode->neighbors.push_back(hmap[c->val]);
            }
            else{
                Node* tnode;
                tnode = dfs(c ,tnode);
                cnode->neighbors.push_back(tnode);
            }
            
        }
        return cnode;
    }
public:
    Node* cloneGraph(Node* node) {
        Node* root;
        root = dfs(node, root);
        return root;
    }
};