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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *start, *end, *node, *prev, *next;
        start=end=prev=next=NULL;
        node = head;
        int cnt = 1;
        while(node){
            if(cnt==left)
                start = node;
            if(!start) prev = node;
            if(cnt == right)
                end = node;
            node = node->next;
            cnt++;
        }
        if(!start || !end) return head;
        node = start;
        next = end->next;
        ListNode *pv, *nx;
        pv=nx=NULL;
        while(node != next){
            nx = node->next;
            node->next = pv;
            pv = node;
            node = nx;
        }
        if(prev)
            prev->next = end;
        else
            head = end;
        start->next = next;
        return head;
    }
};