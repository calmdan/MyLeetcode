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
        if(head == NULL || head->next == NULL) return head;
        ListNode * p = head;
        while(p->next!=NULL)
        {
            if(p->next->val == p->val)
            {
                p->next = p->next->next;
            }
            else p=p->next;
        }
        return head;
    }
};
