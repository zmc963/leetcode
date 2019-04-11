/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution
{
    Node* Traversal( Node* const head ) const
    {
        if( !head ) return nullptr;
        if( !head->next && !head->child ) return head;

        auto child_tail = Traversal( head->child );
        auto next_tail = Traversal( head->next );

        if( child_tail )
        {
            child_tail->next = head->next;
            child_tail->child = nullptr;

            if( head->next ) head->next->prev = child_tail;
            head->next = head->child;
        }

        assert( (head->child && child_tail) || (!head->child && !child_tail) );
        head->child = nullptr;
        head->next->prev = head;

        assert( !next_tail || (next_tail && !next_tail->next && !next_tail->child) );
        return next_tail ? next_tail : child_tail;
    }

public:
    Node* flatten(Node* head)
    {
        Traversal( head );
        return head;
    }
};
