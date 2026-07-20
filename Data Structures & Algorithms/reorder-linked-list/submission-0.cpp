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
    ListNode* findMiddleOfList(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;

        }

        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;

        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            
        }
        return prev;



    }
    void reorderList(ListNode* head) {
        ListNode* mid=findMiddleOfList(head);
        ListNode* itr=head;

        ListNode* curr=NULL;
        curr=mid?mid->next:0;
        mid=mid?mid->next=nullptr:0;

        ListNode* tail=reverseList(curr);
        while(itr || tail){
            ListNode* temp=NULL;
            temp=itr->next;
            itr->next=tail;
            itr=temp;
            temp=tail?tail->next:0;
            tail?tail->next=itr:0;
            tail=temp;

        }

        // return head;

    }
};
