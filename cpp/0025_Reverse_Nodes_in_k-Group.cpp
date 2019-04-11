/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    ListNode* GetKStepsAheadNode( ListNode* head, int k ) const
    {
        for( auto i=0; i<k-1 && head; ++i ) head = head->next;

        return head;
    }

    ListNode* Reverse( ListNode* prev, ListNode* curr, ListNode* last ) const
    {
        while( last != prev )
        {
            auto next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if( k <= 1 ) return head;

        ListNode dummy(0);
        ListNode* prev = &dummy;
        prev->next = head;
        ListNode* curr = head;

        while( auto last = GetKStepsAheadNode( curr, k ) )
        {
            auto new_head = Reverse( prev, curr, last );

            curr->next = new_head;
            prev->next = last;
            prev = curr;
            curr = new_head;
        }

        return dummy.next;
    }
};
