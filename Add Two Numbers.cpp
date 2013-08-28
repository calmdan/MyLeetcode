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
        ListNode *c = new ListNode(0);
        ListNode *res = c;
        ListNode *last = NULL;
        while(l1!=NULL && l2!=NULL)
        {
            c->next = new ListNode((c->val +l1->val +l2->val)/10);
            c->val = (c->val +l1->val +l2->val)%10;
            last = c;
            c = c->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            c->next = new ListNode((c->val +l1->val)/10);
            c->val = (c->val +l1->val)%10;
            last = c;
            c = c->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            c->next = new ListNode((c->val  +l2->val)/10);
            c->val = (c->val +l2->val)%10;
            last = c;
            c = c->next;
            l2=l2->next;
        }
        if(c->val ==0) last->next =NULL;
        return res;
    }
};
