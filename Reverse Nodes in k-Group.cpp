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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k<=1) return head;
        ListNode dummy(0);
        ListNode *tmp = getk(head,k);;

        if(!tmp) return head;

        ListNode *pre = &dummy;
        ListNode *first = head;
        ListNode *last = tmp;
        ListNode *post = NULL;

        while(last)
        {
            post = last->next;
            ListNode * p = first;
            ListNode * q = p->next;
            while(p!=last)
            {
                ListNode *tmp = q->next;
                q->next = p;
                p = q;
                q=tmp;
            }

            pre->next = last;
            first->next = post;

            pre = first;
            first = first->next;
            last = getk(first,k);

        }
        return dummy.next;
    }
    ListNode* getk(ListNode * p,int k)
    {
        int n = 0;
        while(n<k-1 && p !=NULL)
        {
            n++;
            p=p->next;
        }
        if(n==k-1) return p;
        else return NULL;
    }
};
