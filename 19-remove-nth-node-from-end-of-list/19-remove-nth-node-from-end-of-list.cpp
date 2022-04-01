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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt= 0;
        ListNode* node=head;
        while(node){
            cnt++;
            node=node->next;
        }
        node = head;
        cnt-=n;
        if(cnt==0) return head->next;
        while(--cnt >0) node = node->next;
        if(node->next)
            node->next = node->next->next;
            
        return head;
    }
};