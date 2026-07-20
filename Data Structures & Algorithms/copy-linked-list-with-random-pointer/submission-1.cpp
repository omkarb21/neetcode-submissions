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
        if(!head) return head;

        Node* curr=head;
        while(curr){
            Node* copyNode=new Node(curr->val);
            copyNode->next=curr->next;
            curr->next=copyNode;
            curr=copyNode->next;
        }

        curr=head;

        while(curr){

            if(curr->random){
                curr->next->random=curr->random->next;
            }
            curr->next? curr=curr->next->next:nullptr;
        }

        Node* itr=head;
        Node* headToReturn=head->next;
        curr=head;
        while(curr){

            if(curr->next){
                itr=curr->next;
                curr->next=itr->next;
                curr=itr->next;
                itr->next=curr?curr->next:nullptr;

            }
        }


        return headToReturn;
    }
};
