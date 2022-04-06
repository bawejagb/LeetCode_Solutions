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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *n1, *n2, *prev=NULL;
        n1 = head;
        n2 = head->next;
        head = n2;
        while(n1&&n2){
            n1->next = n2->next;
            n2->next = n1;
            prev = n1;
            n1 = n1->next;
            if(n1)
                n2 = n1->next;
            if(n1&&n2&&prev)
                prev->next = n2;
            
        }
        return head;
    }
};