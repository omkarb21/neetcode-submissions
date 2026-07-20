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
        unordered_map<Node*, Node*>originalAndCopies;

        Node* curr=head;

        if(!head) return nullptr;

        while(curr){
            originalAndCopies[curr]=new Node(curr->val);
            curr=curr->next;
        }

        curr=head;

        while(curr){
            if(curr->next){
                originalAndCopies[curr]->next=originalAndCopies[curr->next];
            }
            if(curr->random){
                originalAndCopies[curr]->random=originalAndCopies[curr->random];
            }
            
            curr=curr->next;

        
    }

    return originalAndCopies[head];
}
};