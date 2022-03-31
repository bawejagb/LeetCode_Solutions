/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *lis1, *lis2, *node, *fnode;
        node = head;
        fnode = head->next;
        while(fnode&&fnode->next){
            node = node->next;
            fnode = fnode->next->next;
        }
        lis1 = head;
        lis2 = node->next;
        node->next = NULL;
        ListNode *p,*c,*n;
        p=NULL;
        c = lis2;
        while(c){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        lis2 = p;
        while(lis1&&lis2){
            n = lis1->next;
            lis1->next = lis2;
            p = lis2->next;
            lis2->next = n;
            lis2 = p;
            lis1 = n; 
        }
    }
};