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
    typedef pair<int, ListNode*> pii;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pii, vector<pii>, greater<pii>> qt;
        for(int i = 0; i< lists.size();i++)
            if(lists[i])
                qt.push({lists[i]->val,lists[i]});
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(!qt.empty()){
            auto node = qt.top();
            qt.pop();
            temp->next = new ListNode(node.first);
            temp = temp->next;
            node.second = node.second->next;
            if(node.second)
                qt.push({node.second->val, node.second});
        }
        return head->next;
    }
};