/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* node = head;
        if(!node) return node;
        while(node->prev) node = node->prev;
        head = node;
        while(node){
            if(node->child){
                Node* temp = flatten(node->child);
                Node* end = temp;
                while(end->next) end = end->next;
                if(node->next){
                    node->next->prev = end;
                    end->next = node->next;
                }
                node->next = temp;
                temp->prev = node;
                node->child = NULL;
                node = end->next;
                
            }
            else
            node = node->next;
        }
        return head;
    }
};