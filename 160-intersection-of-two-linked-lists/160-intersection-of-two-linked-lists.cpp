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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA,lenB;
        lenA=lenB=0;
        ListNode* nodeA =headA;
        ListNode* nodeB = headB;
        while(nodeA){
            lenA++;
            nodeA = nodeA->next;
        }
        while(nodeB){
            lenB++;
            nodeB= nodeB->next;
        }
        nodeA = headA;
        nodeB = headB;
        while(lenA > lenB){
            lenA--;
            nodeA = nodeA->next;
        }
        while(lenB > lenA){
            lenB--;
            nodeB = nodeB->next;
        }
        while(nodeA != nodeB){
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return nodeA;
    }
};