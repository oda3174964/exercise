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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        
        ListNode* p = lists[0];
        for(int i = 1; i < lists.size(); i++)
        {
            p = mergeTwoLists(p, lists[i]);
        }
        return p;
    }
    
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2)
    {
        ListNode *p1 = head1,  *p2=head2;
        static ListNode dummy(0);
    
        dummy.next = p1;
        ListNode *prev = &dummy;
    
        while(p1 && p2)
        {
            if(p1->val < p2->val)
            {
                prev = p1;
                p1 = p1->next;
            }else
            {
                prev->next = p2;
                p2 = p2->next;
                prev = prev->next;
                prev->next = p1;
            }
        }
        if (p2)
        {
            prev->next = p2;
        }
    
        return dummy.next;
    }
};