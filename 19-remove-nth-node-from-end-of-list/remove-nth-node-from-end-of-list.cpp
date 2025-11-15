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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || head->next==NULL) return NULL;
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
         if (n == cnt) {
            ListNode* newh =head->next;
            return newh;
        }
        temp=head;
        int k=cnt-n;
        cnt=0;
        while(temp!=NULL){
            cnt++;
            if(cnt==k){
                ListNode* front=temp->next;
                temp->next=temp->next->next;
                delete front;
            }
            temp=temp->next;
        }
        return head;
    }
};