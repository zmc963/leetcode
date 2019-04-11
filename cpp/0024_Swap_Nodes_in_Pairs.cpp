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
        ListNode dummy(0);
        ListNode* tail = &dummy;
        tail->next = head;

        while( tail->next && tail->next->next )
        {
            auto left = tail->next;
            auto right = tail->next->next;
            left->next = right->next;
            right->next = left;
            tail->next = right;

            tail = tail->next->next;
        }

        return dummy.next;
    }
};
