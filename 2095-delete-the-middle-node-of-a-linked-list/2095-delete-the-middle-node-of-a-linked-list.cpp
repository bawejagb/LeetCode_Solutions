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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        if(slow->next==NULL) return NULL;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow->next){
            slow->val = slow->next->val;
            slow->next = slow->next->next;
        }
        else{
            head->next = NULL;
        }
        return head;
    }
};