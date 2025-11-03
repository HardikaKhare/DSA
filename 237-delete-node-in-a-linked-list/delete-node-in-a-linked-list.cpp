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
    void deleteNode(ListNode* node) {
         node->val = node->next->val;      // Step 1: copy next node's value
    ListNode* temp = node->next;      // Step 2: store next node
    node->next = node->next->next;    // Step 3: skip the next node
    delete temp;  
    }
};