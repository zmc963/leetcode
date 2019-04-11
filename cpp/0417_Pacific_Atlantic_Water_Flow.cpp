class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    enum class FLOW { NOT_YET_DECIDED, SUCCESSFUL };

    void Flow(
        const std::vector<std::vector<int>>& matrix,
        SIZE_TYPE row,
        SIZE_TYPE col,
        int prevHeight,
        std::vector<std::vector<FLOW>>& memo ) const
    {
        assert( !memo.empty() );
        assert( matrix.size() == memo.size() );
        assert( matrix.front().size() == memo.front().size() );
        assert( row < matrix.size() );
        assert( col < matrix.front().size() );

        auto curr_height = matrix.at(row).at(col);
        if( prevHeight>curr_height || FLOW::SUCCESSFUL==memo.at(row).at(col) )
        {
            return;
        }

        memo.at(row).at(col) = FLOW::SUCCESSFUL;

        // up
        if( row >= 1 ) Flow( matrix, row-1, col, curr_height, memo );

        // down
        if( row < matrix.size()-1 ) Flow( matrix, row+1, col, curr_height, memo );

        // left
        if( col >= 1 ) Flow( matrix, row, col-1, curr_height, memo );

        // right
        if( col < matrix.front().size()-1 ) Flow( matrix, row, col+1, curr_height, memo );
    }

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
        if( matrix.empty() || matrix.front().empty() ) return {};

        const auto ROW_SIZE = matrix.size();
        const auto COL_SIZE = matrix.front().size();

        std::vector<std::vector<FLOW>> pacific( ROW_SIZE, std::vector<FLOW>( COL_SIZE, FLOW::NOT_YET_DECIDED ) );
        for( SIZE_TYPE col=0; col<COL_SIZE; ++col ) Flow( matrix, 0, col, matrix.front().at(col), pacific );
        for( SIZE_TYPE row=0; row<ROW_SIZE; ++row ) Flow( matrix, row, 0, matrix.at(row).front(), pacific );

        std::vector<std::vector<FLOW>> atlantic( ROW_SIZE, std::vector<FLOW>( COL_SIZE, FLOW::NOT_YET_DECIDED ) );
        for( SIZE_TYPE col=0; col<COL_SIZE; ++col ) Flow( matrix, ROW_SIZE-1, col, matrix.back().at(col), atlantic );
        for( SIZE_TYPE row=0; row<ROW_SIZE; ++row ) Flow( matrix, row, COL_SIZE-1, matrix.at(row).back(), atlantic );

        std::vector<std::pair<int, int>> ans;
        for( SIZE_TYPE row=0; row<ROW_SIZE; ++row )
        {
            for( SIZE_TYPE col=0; col<COL_SIZE; ++col )
            {
                if( FLOW::SUCCESSFUL==pacific.at(row).at(col) &&
                    FLOW::SUCCESSFUL==atlantic.at(row).at(col) )
                {
                    ans.emplace_back( row, col );
                }
            }
        }

        return ans;
    }
};
