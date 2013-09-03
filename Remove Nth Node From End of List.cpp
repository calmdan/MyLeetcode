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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode * p1 = head;
        ListNode * p2 = head;
        for(int i=0;i<n;i++)
        {
            p1 = p1->next;
        }
        if(p1==NULL) return head->next;
        while(p1->next != NULL)
        {
            p1=p1->next;
            p2=p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p1=head, *p2= &dummy;
        n++;
        while(p1!=NULL)
        {
            p1=p1->next;
            n--;
            if(n<=0) p2=p2->next;
        }
        if(n<=1) p2->next = p2->next->next;
        return dummy.next;
    }
};
