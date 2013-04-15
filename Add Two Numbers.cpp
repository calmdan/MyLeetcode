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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *temp = new ListNode(0);
        ListNode *res = temp;
        ListNode *last2 = NULL;
        while(l1!=NULL && l2!=NULL)
        {
            temp->next = new ListNode((temp->val +l1->val +l2->val)/10);
            temp->val = (temp->val +l1->val +l2->val)%10;
            last2 = temp;
            temp = temp->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            temp->next = new ListNode((temp->val +l1->val)/10);
            temp->val = (temp->val +l1->val)%10;
            last2 = temp;
            temp = temp->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            temp->next = new ListNode((temp->val  +l2->val)/10);
            temp->val = (temp->val +l2->val)%10;
            last2 = temp;
            temp = temp->next;
            l2=l2->next;
        }
        if(temp->val ==0) last2->next =NULL;
        return res;
    }
};
