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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add=0;
        ListNode res;
        ListNode* temp;
        temp = &res;
        while(l1||l2||add){
            if(l1){
                add+= l1->val;
                l1=l1->next;
            }
            if(l2){
                add+= l2->val;
                l2=l2->next;
            }
            temp->next = new ListNode(add%10);
            temp = temp->next;
            add /= 10;
        }
        return res.next;
    }
};