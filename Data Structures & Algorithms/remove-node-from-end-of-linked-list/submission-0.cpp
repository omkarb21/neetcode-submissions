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
    int getLengthOfList(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int lengthOfList=getLengthOfList(head);

        int NodeToDelete=lengthOfList-n;

        ListNode* itr=head;
        ListNode* prev=NULL;
        if(itr){
            for(int i=0;i<NodeToDelete;i++){
                prev=itr;
                itr=itr->next;
            }
            prev?prev->next=itr->next:head=itr->next;
            itr->next=NULL;
            delete itr;
        }
        return head;
    }
};
