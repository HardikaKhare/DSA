/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * temp=head;
        map<Node*,Node *> mpp;
        Node * dummy=new Node(-1);
        Node * curr=dummy;
        while(temp!=NULL){  
            Node* newnode=new Node(temp->val);
            mpp[temp]=newnode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            curr=mpp[temp];
            curr->next=mpp[temp->next];
            curr->random=mpp[temp->random];
            temp=temp->next;
        }
        return  mpp[head];
    }
};