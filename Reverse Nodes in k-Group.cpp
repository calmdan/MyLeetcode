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



class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || k <= 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;

        int i = 0;
        while (head) {
            i++;
            if (i % k == 0) {
                pre = reverse(pre, head->next);                
                head = pre->next;
            } else {
                head = head->next;   
            }
        }

        return dummy.next;
    }

    ListNode *reverse(ListNode *pre, ListNode *next) {
        ListNode *last = pre->next;
        ListNode *cur = last->next;
        while (cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;

            cur = last->next;
        }
        return last;
    }
};
