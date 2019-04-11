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
    using SIZE_TYPE = std::vector<int>::size_type;

    bool IsLeaf(
        const std::vector<std::vector<int>>& grid,
        const std::pair<SIZE_TYPE, SIZE_TYPE>& upperLeft,
        SIZE_TYPE len,
        int& cnt ) const
    {
        cnt = 0;
        for( auto row=upperLeft.first; row<upperLeft.first+len; ++row )
        {
            for( auto col=upperLeft.second; col<upperLeft.second+len; ++col )
            {
                assert( 1==grid.at(row).at(col) || 0==grid.at(row).at(col) );

                if( 1 == grid.at(row).at(col) ) ++cnt;
            }
        }

        return cnt==len*len || cnt==0;
    }

    Node* ConstructQuadTree(
        const std::vector<std::vector<int>>& grid,
        const std::pair<SIZE_TYPE, SIZE_TYPE>& upperLeft,
        SIZE_TYPE len ) const
    {
        assert( upperLeft.first+len <= grid.size() );
        assert( upperLeft.second+len <= grid.front().size() );

        int val = 0;
        if( IsLeaf( grid, upperLeft, len, val ) )
        {
            return new Node( val, true, nullptr, nullptr, nullptr, nullptr );
        }

        Node* root = new Node( -1, false );
        root->topLeft = ConstructQuadTree( grid, upperLeft, len/2 );
        root->topRight = ConstructQuadTree( grid, {upperLeft.first, upperLeft.second+len/2}, len/2 );
        root->bottomLeft = ConstructQuadTree( grid, {upperLeft.first+len/2, upperLeft.second}, len/2 );
        root->bottomRight = ConstructQuadTree( grid, {upperLeft.first+len/2, upperLeft.second+len/2}, len/2 );

        return root;
    }

public:
    Node* construct(vector<vector<int>>& grid)
    {
        return ConstructQuadTree( grid, {0, 0}, grid.size() );
    }
};
