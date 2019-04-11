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
    ListNode* m_head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) :
        m_head(head)
    {}

    /** Returns a random node's value. */
    int getRandom()
    {
        std::random_device rd;
        std::default_random_engine gen = std::default_random_engine(rd());

        auto head = m_head;
        auto target = -1;

        for( auto n=1; head; head=head->next, ++n )
        {
            std::uniform_int_distribution<int> dis(1, n);

            target = dis(gen)==1 ? head->val : target;
        }

        return target;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
