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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next) return head;
        int cnt = 0;
        ListNode* node = head;
        while(node){
            cnt++;
            node = node->next;
        }
        cnt -= k%cnt;
        ListNode *temp;
        node = head;
        while(--cnt>0)
            node = node->next;
        if(node->next){
            temp = node->next;
            while(temp->next)
                temp = temp->next;
            temp->next = head;
            head = node->next;
            node->next = NULL;
        }
        return head;
    }
};