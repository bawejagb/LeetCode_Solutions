/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hset;
        while(head){
            if(hset.find(head)==hset.end())
                hset.insert(head);
            else return head;
            head = head->next;
        }
        return NULL;
    }
};