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
    bool isPalindrome(ListNode* head) {
      ListNode* h2;
        ListNode* next;
        ListNode* prev;
        prev = NULL;
        h2 = head->next;
        ListNode* h1 = head;
        while(h1 && h2 && h2->next){
            h1 = h1->next;
            h2 = h2->next->next;
        }
        h2 = h1->next;
        if(!h2) return 1;
        h1->next = NULL;
        h1 = head;
        while(h2){
            next = h2->next;
            h2->next = prev;
            prev = h2;
            h2 = next;
        }
        h2 = prev;
        while(h1 && h2){
            if(h1->val != h2->val) return 0;
            h1 = h1->next;
            h2 = h2->next;
        }
    
        return 1;
    }
};