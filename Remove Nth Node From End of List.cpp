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
