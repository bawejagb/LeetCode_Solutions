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
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            result = l1;
            l1 = l1->next;
        } else {
            result = l2;
            l2 = l2->next;
        }
        ListNode* node = result;
        while(l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                node->next = l2;
                break;
            } else if (l2 == nullptr) {
                node->next = l1;
                break;
            } else if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        return result;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int n = lists.size();
        if (n == 0) return nullptr;
        std::queue<ListNode*> nodes;
        for (ListNode* node : lists) nodes.push(node);
        while(nodes.size() > 1) {
            ListNode* l1 = nodes.front();
            nodes.pop();
            ListNode* l2 = nodes.front();
            nodes.pop();
            ListNode* m = mergeTwoList(l1, l2);
            nodes.push(m);
        }
        return nodes.front(); 
    }
};