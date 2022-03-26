/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node;
        if(!head) return head;
        Node* temp=head;
        Node* res;
        while(temp){
            node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = temp->next->next;
        }
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        res = node = temp->next;
        while(temp){
            if(temp->next)
                temp->next = temp->next->next;
            temp = temp->next;
            if(node->next)
                node->next = node->next->next;
            node = node->next;
        }
        return res;
    }
};