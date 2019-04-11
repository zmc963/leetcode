/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct Cmp
    {
        bool operator()(ListNode *p, ListNode *q) const {
            return p->val > q->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        const auto SIZE = lists.size();

        std::priority_queue<ListNode*, std::vector<ListNode*>, Cmp> pq;
        for( std::vector<ListNode*>::size_type i=0; SIZE>i; ++i )
        {
            if( lists.at(i) ) pq.push(lists.at(i));
        }

        while( !pq.empty() )
        {
            tail->next = pq.top();
            pq.pop();

            tail = tail->next;
            if( tail->next ) pq.push(tail->next);
        }

        return dummy.next;
    }
};
