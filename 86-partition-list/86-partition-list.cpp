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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode bef, aft;
        ListNode *b, *a;
        b = &bef;
        a = &aft;
        while(head){
            if(head->val < x){
                b->next = head;
                b = head;
                head = head->next;
                b->next = NULL;
            }
            else{
                a->next = head;
                a = head;
                head = head->next;
                a->next = NULL;
            }
        }
        b->next = aft.next;
        return bef.next;
    }
    
};