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
    ListNode* swapPairs(ListNode* head) 
    {
        for(ListNode* p = head; p != nullptr; )
        {
            int tmp = p->val;
            if(p->next)
            {
                p->val = p->next->val;
                p->next->val = tmp;
            }
            if(p->next && p->next->next)
                p = p->next->next;
            else
                p = p->next;
                
        }
        return head;
    }
};