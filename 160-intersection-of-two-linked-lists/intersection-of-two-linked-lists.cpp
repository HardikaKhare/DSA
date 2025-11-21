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
        if (!headA || !headB) return nullptr;
        ListNode * a=headA;
        ListNode * b=headB;
        int n1=0;
        int  n2=0;
        while(a!=NULL){
            n1++;
            a=a->next;
        }
        while(b!=NULL){
            n2++;
            b=b->next;
        }
        b=headB;
        a=headA;
        int d=0;
        if(n2>n1) d=n2-n1;
        else d=n1-n2;
        if(n2>n1){
        while(d!=0){
            b=b->next;
            d--;
        }
        }else{
            while(d!=0){
            a=a->next;
            d--;
        }

        }
        while(a!=b){
            a=a->next;
            b=b->next;
        }
        if(a==b)return a;
 else return nullptr;
    }
};