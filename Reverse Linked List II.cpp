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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==n) return head;
        ListNode *pre_m=NULL,*p1=head,*p2=NULL;
        int c=1;
        while(c<m)
        {
            pre_m = p1;
            p1 = p1->next;
            c++;
        }
        ListNode * mm = p1;
        p2=p1;
        p1=p1->next;
        c++;
        while(c<=n)
        {
            ListNode * t = p1->next;
            p1->next = p2;
            p2 = p1;
            p1 = t;
            c++;
        }
        mm->next = p1;
        if(pre_m ==NULL) return p2;
        pre_m->next = p2;
        return head;
    }
};
//简洁难懂的代码
ListNode *reverseBetween(ListNode *head, int m, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode dummy(0);
    dummy.next = head;

    ListNode *preM, *pre = &dummy;
    for (int i = 1; i <= n; ++i) {
        if (i == m) preM = pre;

        if (i > m && i <= n) {
            pre->next = head->next;
            head->next = preM->next;
            preM->next = head;
            head = pre; // head has been moved, so pre becomes current
        }

        pre = head;
        head = head->next;
    }

    return dummy.next;
}
