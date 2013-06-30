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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return NULL;
        ListNode * p = head;
        ListNode * end = head;
        int num =1;
        while(end->next != NULL)
        {
            end = end->next;
            num++;
        }
        if(k %num ==0) return head;//here handles it 
        k=num - k % num;
        for(int i=1;i<k;i++)
        {
            p = p->next;
        }
        ListNode * result = p->next;//can not be NULL
        end->next = head;
        p->next = NULL;
        return result;
    }
};
