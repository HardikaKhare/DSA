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
        map<ListNode*,int> mpp;
        while(a!=NULL){
            mpp[a]=1;
            a=a->next;
        }
        while(b!=NULL){
            if(mpp.find(b)!=mpp.end()) return b;
            b=b->next;
        }
 return nullptr;
    }
};