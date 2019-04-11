class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

    void DFS(
        const std::vector<std::vector<int>>& matrix,
        SIZE_TYPE curr,
        std::vector<int>& visited ) const
    {
        assert( curr < matrix.size() );
        assert( matrix.size() == visited.size() );

        visited.at(curr) = true;

        const auto SIZE = matrix.at(curr).size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            if( !visited.at(i) && 1==matrix.at(curr).at(i) )
            {
                DFS( matrix, i, visited );
            }
        }
    }

    SIZE_TYPE FindRoot( SIZE_TYPE curr, std::vector<int>& root ) const
    {
        while( curr != root.at(curr) )
        {
            root.at(curr) = root.at(root.at(curr)); // path compression by halving
            curr = root.at(curr);
        }

        return curr;
    }

public:
    int findCircleNum( std::vector<std::vector<int>>& matrix )
    {
        if( matrix.empty() || matrix.front().empty() ) return {};

        const auto SIZE = matrix.size();
        SIZE_TYPE circles = SIZE;
        std::vector<int> root(SIZE);
        std::vector<int> size(SIZE);
        for( auto i=0; i<SIZE; ++i )
        {
            root.at(i) = i;
            size.at(i) = 1;
        }

        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            for( SIZE_TYPE j=i+1; j<SIZE; ++j )
            {
                if( 1 == matrix.at(i).at(j) )
                {
                    auto first_root = FindRoot( i, root );
                    auto second_root = FindRoot( j, root );
                    if( first_root != second_root )
                    {
                        assert( circles >= 0 );
                        --circles;

                        // union by size
                        if( size[first_root] < size[second_root] )
                        {
                            size[second_root] += size[first_root];
                            root[first_root] = second_root;
                        }
                        else
                        {
                            size[first_root] += size[second_root];
                            root[second_root] = first_root;
                        }
                    }
                }
            }
        }

        return circles;
    }
};
