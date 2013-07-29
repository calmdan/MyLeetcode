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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        for(auto i = lists.begin();i!=lists.end();)
        {
            if(*i ==NULL) 
            {
                lists.erase(i);
                continue;
            }
            i++;
        }
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        make_heap(lists.begin(),lists.end(),cmp());
        ListNode* res = NULL;
        ListNode* cur = NULL;
        while(lists.size()>0)
        {
            if(res==NULL) 
            {
                res =cur= lists[0];
            }
            else 
            {
                cur->next = lists[0];
                cur = cur->next;
            }
            pop_heap(lists.begin(),lists.end(),cmp());
            int last = lists.size()-1;
            if(cur->next == NULL) lists.pop_back();
            else 
            {
                lists[last] = lists[last]->next;
                push_heap(lists.begin(),lists.end(),cmp());
            }
        }
        return res;
    }

    struct cmp: public binary_function<ListNode*, ListNode*, bool> {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
};
