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
        if (!head) return NULL;
        Node * temp=head;
        while(temp!=NULL){  
            Node * newnode= new Node(temp->val);
            newnode->next=temp->next;
             temp->next=newnode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=0){
            if (temp->random)
    temp->next->random = temp->random->next;
else
    temp->next->random = NULL;

            temp=temp->next->next;
        }
        Node*dummy=new Node (-1);
        temp=head;
        Node* curr=dummy;
        while(temp!=NULL){
            curr->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            curr=curr->next;
        }
        return dummy->next;
    }
};