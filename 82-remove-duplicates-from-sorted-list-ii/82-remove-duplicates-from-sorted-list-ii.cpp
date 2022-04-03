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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp, *node = head;
        temp = NULL;
        while(node){
            bool fg=0;
            while(node->next&&node->next->val==node->val){
                fg=1;
                node = node->next;
            }
            if(!fg){
                if(!temp){
                    temp = head = node;
                }
                else temp->next = node;
                temp = node;
            }
            else if(temp) temp->next = NULL;
            node = node->next;
            
        }
        if(!temp) return temp;
        return head;
    }
};