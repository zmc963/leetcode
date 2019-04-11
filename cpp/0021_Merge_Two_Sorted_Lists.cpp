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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        while( l1 && l2 )
        {
            if( l1->val <= l2->val )
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
            }

            prev = prev->next;
        }

        prev->next = l2 ? l2 : l1;
        return dummy.next;
    }
};
