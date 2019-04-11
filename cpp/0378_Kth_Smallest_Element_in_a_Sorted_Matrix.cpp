class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    // same idea with "#4. Median of Two Sorted Arrays", T(k) = T((n-1/n)k) + n where n is the row size
    int FindKthSmallest( const vector<vector<int>>& matrix, int k, std::vector<SIZE_TYPE>& colStart ) const
    {
        assert( colStart.size() == matrix.size() );
        assert( k > 0 );

        const auto ROW_SIZE = matrix.size();
        const auto COL_SIZE = matrix.front().size();

        if( k >= ROW_SIZE*COL_SIZE ) return matrix.back().back();

        int min_val = std::numeric_limits<decltype(min_val)>::max();
        SIZE_TYPE min_val_row_idx = std::numeric_limits<decltype(min_val_row_idx)>::max();
        SIZE_TYPE new_col_start_idx = std::numeric_limits<decltype(new_col_start_idx)>::max();

        auto base_k = k / matrix.size();

        for( SIZE_TYPE i=0; i<ROW_SIZE; ++i )
        {
            auto start_col_idx = colStart.at(i);
            if( start_col_idx == COL_SIZE ) continue;

            auto target_col_idx = std::min( start_col_idx+(base_k==0?0:base_k-1), COL_SIZE-1 );
            auto target_val = matrix.at(i).at(target_col_idx);
            assert( start_col_idx < COL_SIZE && target_col_idx < COL_SIZE );

            if( min_val > target_val )
            {
                min_val = target_val;
                min_val_row_idx = i;
                new_col_start_idx = target_col_idx;
            }
        }

        assert( min_val != std::numeric_limits<decltype(min_val)>::max() );
        assert( new_col_start_idx >= colStart.at(min_val_row_idx) );

        k -= new_col_start_idx - colStart.at(min_val_row_idx) + 1;
        colStart.at(min_val_row_idx) = new_col_start_idx + 1;

        return k==0 ? min_val : FindKthSmallest( matrix, k, colStart ) ;
    }

public:
    int kthSmallest( vector<vector<int>>& matrix, int k )
    {
        const auto INVALID = -1;
        if( matrix.empty() || k < 0 ) return INVALID;

        std::vector<SIZE_TYPE> start( matrix.size(), 0 );
        return FindKthSmallest( matrix, k, start );
    }
};
