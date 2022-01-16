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
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        int sum=0,carry=0;
        while(l1 && l2){
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            ListNode* node= new ListNode(sum%10);
            temp->next=node;
            l1=l1->next;
            l2=l2->next;
            temp=temp->next;
        }
        while(l1){
            sum=l1->val+carry;
            carry=sum/10;
            ListNode* node= new ListNode(sum%10);
            temp->next=node;
            l1=l1->next;
            temp=temp->next;
        }
        while(l2){
            sum=l2->val+carry;
            carry=sum/10;
            ListNode* node= new ListNode(sum%10);
            temp->next=node;
            l2=l2->next;
            temp=temp->next;
        }
        while(carry){
            ListNode* node= new ListNode(carry);
            temp->next=node;
            temp=temp->next;
            carry=0;
        }
        return dummy->next;
    }
};