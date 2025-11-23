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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode*t2=l2;
        int carry=0;
        ListNode*dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(t1!=0 && t2!=0){
            
            int sum=carry+t1->val+t2->val;
            if(sum<10){
                ListNode* newh= new ListNode(sum);
                temp->next=newh;
                carry=0;
            }else{
                ListNode* newh=new ListNode(sum-10);
                temp->next=newh;
                carry=1;
            }
            t1=t1->next;
            t2=t2->next;
            temp=temp->next;
        }while (t1 != nullptr) {
            int sum = carry + t1->val;

            if (sum < 10) {
                temp->next = new ListNode(sum);
                carry = 0;
            } else {
                temp->next = new ListNode(sum - 10);
                carry = 1;
            }

            t1 = t1->next;
            temp = temp->next;
        }

        // PART 3: process remaining nodes of l2
        while (t2 != nullptr) {
            int sum = carry + t2->val;

            if (sum < 10) {
                temp->next = new ListNode(sum);
                carry = 0;
            } else {
                temp->next = new ListNode(sum - 10);
                carry = 1;
            }

            t2 = t2->next;
            temp = temp->next;
        }
        if(carry==1){
            ListNode* neww=new ListNode(1);
            temp->next=neww;

        }
        return dummy->next;
    }
};