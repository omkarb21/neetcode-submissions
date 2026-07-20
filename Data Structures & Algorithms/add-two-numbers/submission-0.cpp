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
        ListNode* resultList=new ListNode(-1);
        ListNode* resultHead=resultList;
        int result=0, carry=0;

        while(l1 || l2|| carry){
            result=(l1?l1->val:0) +carry;
            result+=l2?l2->val:0;

            int digits=result%10;
            carry=result/10;
            ListNode* temp=new ListNode(digits);
            resultList->next=temp;
            
            resultList = resultList->next;

            l1=l1?l1->next:0;
            l2=l2?l2->next:0;



        }

        return resultHead->next;
    }
};
