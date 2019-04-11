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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        std::stack<int> num1;
        std::stack<int> num2;

        for( ; l1; l1=l1->next ) num1.push( l1->val );
        for( ; l2; l2=l2->next ) num2.push( l2->val );

        ListNode dummy(-1);
        ListNode* head = nullptr;
        int carry = 0;
        const auto BASE = 10;
        while( !num1.empty() || !num2.empty() || carry!=0 )
        {
            auto digit_1 = 0;
            if( !num1.empty() )
            {
                digit_1 = num1.top();
                num1.pop();
            }

            auto digit_2 = 0;
            if( !num2.empty() )
            {
                digit_2 = num2.top();
                num2.pop();
            }

            auto new_digit = digit_1 + digit_2 + carry;
            carry = new_digit / BASE;
            new_digit %= BASE;

            auto new_node = new ListNode(new_digit);
            new_node->next = head;
            head = new_node;
        }

        return head;
    }
};
