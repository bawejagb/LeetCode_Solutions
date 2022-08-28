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
    ListNode* res=NULL;
    int addNodes(ListNode* l1, ListNode* l2, int l1Count, int l2Count){
        if(l1Count==0&&l2Count==0) return 0;
        int carry,sum = 0;
        if(l1Count>l2Count){
            carry = addNodes(l1->next, l2, l1Count-1, l2Count);
            sum += l1->val;
        }
        else if(l2Count>l1Count){
            carry = addNodes(l1, l2->next, l1Count, l2Count-1);
            sum += l2->val;
        }
        else{
            carry = addNodes(l1->next, l2->next, l1Count-1, l2Count-1);
            sum += l1->val + l2->val;
        }
        sum += carry;
        ListNode* node = new ListNode(sum%10);
        node->next = res;
        res = node;
        return sum/10;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1Count=0,l2Count=0;
        ListNode* temp = l1;
        while(temp){
            temp = temp->next;
            l1Count++;
        }
        temp = l2;
        while(temp){
            temp = temp->next;
            l2Count++;
        }
        bool carry = addNodes(l1, l2, l1Count, l2Count);
        if(carry){
            ListNode* node = new ListNode(1);
            node->next = res;
            res = node;
        }
        return res;
    }
};