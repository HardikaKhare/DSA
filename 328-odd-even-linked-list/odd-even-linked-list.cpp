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
        ListNode* temp=head;
        queue<int> st;
        int cnt=1;
        while(temp!=NULL){
            if(cnt % 2 != 0){
                st.push(temp->val);
            }
            cnt++;
            temp=temp->next;
        }
        cnt=1;
        temp=head;
        while(temp!=NULL){
            if(cnt % 2 == 0){
                st.push(temp->val);
            }
            cnt++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            temp->val=st.front();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
};