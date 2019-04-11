/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution
{
    Node* DeepCopy( Node* quadTree ) const
    {
        if( !quadTree ) return nullptr;

        return new Node( quadTree->val, quadTree->isLeaf, DeepCopy(quadTree->topLeft), DeepCopy(quadTree->topRight), DeepCopy(quadTree->bottomLeft), DeepCopy(quadTree->bottomRight) );
    }

    Node* IntersectImp( Node* quadTree1, Node* quadTree2 ) const
    {
        if( !quadTree1 && !quadTree2 )
        {
            return nullptr;
        }
        else if( quadTree1 && quadTree1->isLeaf && quadTree2 && quadTree2->isLeaf )
        {
            return new Node( quadTree1->val | quadTree2->val, true, nullptr, nullptr, nullptr, nullptr );
        }
        else if( quadTree1 && quadTree1->isLeaf )
        {
            return (quadTree1->val || !quadTree2) ? new Node( quadTree1->val, true, nullptr, nullptr, nullptr, nullptr ) : DeepCopy(quadTree2);
        }
        else if( quadTree2 && quadTree2->isLeaf )
        {
            return (quadTree2->val || !quadTree1) ? new Node( quadTree2->val, true, nullptr, nullptr, nullptr, nullptr ) : DeepCopy(quadTree1);
        }

        assert( quadTree1 && quadTree2 && !quadTree1->isLeaf && !quadTree2->isLeaf );

        auto top_left = IntersectImp( quadTree1->topLeft, quadTree2->topLeft );
        auto top_right = IntersectImp( quadTree1->topRight, quadTree2->topRight );
        auto bottom_left = IntersectImp( quadTree1->bottomLeft, quadTree2->bottomLeft );
        auto bottom_right = IntersectImp( quadTree1->bottomRight, quadTree2->bottomRight );

        // why doing an union needs to perform this operation....
        if( top_left->val == top_right->val && top_left->val == bottom_left->val && top_left->val == bottom_right->val &&
            top_left->isLeaf && top_right->isLeaf && bottom_left->isLeaf && bottom_right->isLeaf )
        {
            auto val = top_left;
            // the delete is not correct since the definiion of Node's dtor doesn't delte its children
            delete top_left; delete top_right; delete bottom_left; delete bottom_right;
            return new Node( val, true, nullptr, nullptr, nullptr, nullptr );
        }

        return new Node( false, false, top_left, top_right, bottom_left, bottom_right );
    }

public:
    Node* intersect( Node* quadTree1, Node* quadTree2 )
    {
        return IntersectImp( quadTree1, quadTree2 );
    }
};
