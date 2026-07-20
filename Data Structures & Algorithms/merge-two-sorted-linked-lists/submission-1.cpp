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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list1_itr= list1;
        ListNode* list2_itr=list2;
        ListNode* curr=new ListNode(-1);
        ListNode* currHead=curr;

        while(list1_itr || list2_itr){
            int l1_data=list1_itr?list1_itr->val:INT_MAX;
            int l2_data=list2_itr?list2_itr->val:INT_MAX;

            if(l1_data<l2_data){
                curr->next=list1_itr;
                curr=list1_itr;
                list1_itr=list1_itr->next;

            }
            else{
                curr->next=list2_itr;
                curr=list2_itr;
                list2_itr=list2_itr->next;

            }
        }

        return currHead->next;
    }
};
