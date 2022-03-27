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
    ListNode* reverse(ListNode* l1){
        ListNode* prev = NULL;
        ListNode* node = l1;
        ListNode* next;
        while(node){
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
            
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a1;
        ListNode* a2;
        ListNode res;
        ListNode* node = &res;
        a1 = reverse(l1);
        a2 = reverse(l2);
        int sum=0;
        while(a1||a2||sum>0){
            if(a1){
                sum += a1->val;
                a1 = a1->next;
            }
            if(a2){
                sum += a2->val;
                a2 = a2->next;
            }
            node->next = new ListNode(sum%10);
            sum /= 10;
            node = node->next;
        }
        return reverse(res.next);
    }
};