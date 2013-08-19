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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return head;
        ListNode res1(0);
        ListNode res2(0);
        ListNode *p=head,*cur1=&res1,*cur2=&res2;
        while(p!=NULL)
        {
            if(p->val < x)
            {
                 ListNode *t = new ListNode(p->val);
                 cur1->next = t;
                 cur1 = cur1->next;
            }
            else
            {
                ListNode *t = new ListNode(p->val);
                 cur2->next = t;
                 cur2 = cur2->next;
            }
            p=p->next;
        }

        cur1->next = res2.next;
        return res1.next;
    }
};
