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
    ListNode* midNode(ListNode* node){
        if(!node) return NULL;
        ListNode* fast = node->next;
        while(fast&&fast->next){
            fast = fast->next->next;
            node = node->next;
        }
        fast = node->next;
        node->next = NULL;
        return fast;
    }
    ListNode* merge(ListNode* lis1, ListNode* lis2){
        if(!lis2) return lis1;
        if(!lis1) return lis2;
        ListNode *head, *temp;
        head = temp = NULL;
        while(lis1&&lis2){
            if(lis1->val<lis2->val){
                if(!head)  temp = head = lis1;
                else {
                    temp->next = lis1;
                    temp = temp->next;
                }
                lis1 = lis1->next;
            }
            else{
                if(!head) temp = head = lis2;
                else{
                    temp->next = lis2;
                    temp = temp->next;
                }
                lis2 = lis2->next;
            }
            temp->next = NULL;
        }
        while(lis1){
            if(!head)  temp = head = lis1;
            else {
                temp->next = lis1;
                temp = temp->next;
            }
            lis1 = lis1->next;
            temp->next = NULL;
        }
        while(lis2){
            if(!head)  temp = head = lis2;
            else {
                temp->next = lis2;
                temp = temp->next;
            }
            lis2 = lis2->next;
            temp->next = NULL;
        }
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode *left, *mid;
        if(!head || !head->next) return head;
        mid = midNode(head);
        left = head;
        left = sortList(left);
        mid = sortList(mid);
        head = merge(left,mid);
        return head;
    }
};