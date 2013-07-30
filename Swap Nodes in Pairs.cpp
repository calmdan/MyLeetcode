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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* p = head;
        ListNode* pre = NULL;
        if(head == NULL || head->next == NULL) return head;
        else head = head->next;
        while(p!=NULL && p->next !=NULL)
        {
            
            ListNode* tmp = p->next;
            p->next = p->next->next;
            tmp->next=p;
            if(pre == NULL) pre = p;
            else 
            {
                pre->next = tmp;
                pre = p;
            }
            p = p-> next;
            
        }
        return head;
    }
};
