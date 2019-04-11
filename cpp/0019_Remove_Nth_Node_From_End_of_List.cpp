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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if( !head || (0 >= n) ) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        auto i = 1;
        for( i=1; i<=n && fast; ++i )
        {
            fast = fast->next;
        }

        if( n >= i ) return nullptr;

        ListNode* slow = &dummy;
        while( fast->next )
        {
            slow = slow->next;
            fast = fast->next;
        }

        auto target = slow->next;
        slow->next = slow->next->next;
        target->next = nullptr;
        return dummy.next;

//         assert( head );
//         assert( n >= 1 );

//         ListNode* p_dummy = new ListNode(0);
//         p_dummy->next = head;
//         auto p_first_node = p_dummy;
//         auto p_second_node = p_dummy;

//         const auto STEP = n+1;
//         for( auto i=0; i<STEP; ++i )
//         {
//             p_first_node = p_first_node->next;
//         }

//         while( p_first_node )
//         {
//             p_first_node = p_first_node->next;
//             p_second_node = p_second_node->next;
//         }

//         p_second_node->next = p_second_node->next->next;

//         return p_dummy->next;
    }
};
