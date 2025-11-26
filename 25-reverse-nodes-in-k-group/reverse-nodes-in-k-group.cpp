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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* front=nullptr;
        ListNode* temp=head;
        while(temp!=NULL){
            front =temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode* temp=head;
        ListNode* previo = NULL;    
        ListNode* newhead = NULL; 
        while(temp!=NULL){
            int a=k;
            ListNode* kth=temp;
            while(a>1 && kth != nullptr){
                kth=kth->next;
                a--;
            }
            if (kth == nullptr) break;
            ListNode* nextnode=kth->next;
            kth->next=NULL;
            ListNode* revhead=reverse(temp);
            if(newhead == NULL) newhead = revhead;
            if(previo != NULL){
                previo->next = revhead;
            }
            previo=temp;
            previo->next=nextnode;
            temp=nextnode;
        }
        return newhead;
    }
};