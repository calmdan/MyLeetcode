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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head ==NULL || head->next ==NULL) return head;
        ListNode * p =head;
        ListNode * pre=NULL;
        while(p!=NULL && p->next!=NULL)
        {
            if(p->next->val ==p->val)
            {
                ListNode * t=p;
                while(t->next!=NULL && t->next->val ==t->val) t=t->next;
                if(p==head)
                {
                    if(t->next==NULL) return NULL;
                    head = t->next;
                    p=t->next;
                }
                else
                {
                    if(t->next==NULL) 
                    {
                        pre->next = NULL;
                        return head;
                    }

                    pre->next = t->next;
                    p=t->next;
                }
            }
            else{
                pre =p;
                p=p->next;
            }
        }
        return head;
    }
};
