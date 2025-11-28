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
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=0){
        ListNode* front=temp->next;;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    int length(ListNode* head){
        ListNode* temp=head;
        int l=0;
        while(temp!=NULL){
            l++;
           
            temp=temp->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int l = length(head);
    k = k % l;
    if(k == 0) return head;

    int a = l - k;         // pivot
    ListNode* temp = head; 
    ListNode* newhead = nullptr;

    // move temp to pivot-1 node
    ListNode* kth = temp;
    int steps = a - 1;
    while(steps > 0){
        kth = kth->next;
        steps--;
    }

    // cut the list into two parts
    ListNode* nextnode = kth->next;
    kth->next = nullptr;

    // reverse first part
    ListNode* revhead1 = reverse(temp);

    // reverse second part
    ListNode* revhead2 = reverse(nextnode);

    // join revhead1 tail → revhead2
    ListNode* joiner = revhead1;
    while(joiner->next != nullptr){
        joiner = joiner->next;
    }
    joiner->next = revhead2;

    // final reverse
    ListNode* finalhead = reverse(revhead1);
    return finalhead;
    }
};