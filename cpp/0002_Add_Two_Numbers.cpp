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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        assert(l1 && l2);

        ListNode* p_first_node = nullptr;
        ListNode* p_prev_node = nullptr;

        int carry = 0;
        do
        {

            int x = (nullptr != l1) ? l1->val : 0;
            int y = (nullptr != l2) ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            sum %= 10;

            ListNode* p_curr_node = new ListNode{sum};
            if( nullptr != p_prev_node )
            {
                p_prev_node->next = p_curr_node;
            }
            else
            {
                p_first_node = p_curr_node;
            }
            p_prev_node = p_curr_node;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;

//             if( (nullptr != l1) )
//             {
//                 if( nullptr != l2 )
//                 {
//                     sum = l1->val + l2->val + carry;
//                     carry = sum / 10;
//                     sum %= 10;

//                     l1 = l1->next;
//                     l2 = l2->next;
//                 }
//                 else
//                 {
//                     assert(!l2 && "l2 should be nullptr");
//                     sum = l1->val + carry;
//                     carry = sum / 10;
//                     sum %= 10;

//                     l1 = l1->next;
//                 }
//             }
//             else
//             {
//                 if( nullptr != l2 )
//                 {
//                     assert(!l1 && "l1 should be nullptr");
//                     sum = l2->val + carry;
//                     carry = sum / 10;
//                     sum %= 10;

//                     l2 = l2->next;
//                 }
//                 else
//                 {
//                     assert(!l1 && !l2 && !"l1 & l2 should not be nullptr at the same time");
//                 }
//             }

//             ListNode* p_curr_node = new ListNode{sum};
//             if( nullptr != p_prev_node )
//             {
//                 p_prev_node->next = p_curr_node;
//             }
//             else
//             {
//                 p_first_node = p_curr_node;
//             }
//             p_prev_node = p_curr_node;

//             assert( p_prev_node );
        }while( l1 || l2 );

        if( 1 == carry )
        {
            p_prev_node->next = new ListNode{1};
        }
        else
        {
            assert( !carry && "carry should be 0" );
        }

        return p_first_node;
    }
};
