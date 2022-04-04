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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenHead, *evenNode, *oddHead, *oddNode;
        if(!head) return head;
        oddNode = oddHead = head;
        evenNode = evenHead = head->next;
        while(evenNode && oddNode){
            oddNode->next = evenNode->next;
            if(oddNode->next){
                oddNode = oddNode->next;
                evenNode->next = oddNode->next;
            }
            else
                evenNode->next = NULL;
            evenNode = evenNode->next;
        }
        oddNode->next = evenHead;
        return oddHead;
    }
};