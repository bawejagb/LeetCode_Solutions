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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur, *prev, *nxt, *temp;
        cur = head;
        int n  = 0;
        while(cur){
            n++;
            cur = cur->next;
        }
        prev = temp = new ListNode(-1,head);
        while(n>=k){
            cur = prev->next;
            nxt = cur->next;
            for(int i=1;i<k;i++){
                cur->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = cur->next;
            }
            prev = cur;
            n-=k;
        }
        return temp->next;
    }
};