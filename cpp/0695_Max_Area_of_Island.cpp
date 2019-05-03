class Solution
{
    using GRID_TYPE = int;
    using SIZE_TYPE = std::vector<GRID_TYPE>::size_type;

    static constexpr auto LAND = 1;
    static constexpr auto MARKED = -1;

    static_assert( std::is_same<typename std::decay<decltype(MARKED)>::type, GRID_TYPE>::value, "" );
    static_assert( std::is_same<typename std::decay<decltype(LAND)>::type, GRID_TYPE>::value, "" );

    int DFS( SIZE_TYPE row, SIZE_TYPE col, vector<vector<GRID_TYPE>>& grid ) const
    {
        assert( row < grid.size() );
        assert( col < grid.at(row).size() );

        if( LAND != grid.at(row).at(col) ) return 0;

        grid.at(row).at(col) = MARKED;

        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        const auto ROW_SIZE = grid.size();
        const auto COL_SIZE = grid.at(row).size();

        auto area = 1;
        for( auto i=0; i<sizeof(dir)/sizeof(dir[0]); ++i )
        {
            auto new_row = row + dir[i][0];
            auto new_col = col + dir[i][1];

            if( new_row<ROW_SIZE && new_col<COL_SIZE && LAND==grid.at(new_row).at(new_col) )
            {
                area += DFS( new_row, new_col, grid );
            }
        }

        return area;
    }

public:
    int maxAreaOfIsland( std::vector<std::vector<GRID_TYPE>>& grid )
    {
        auto max_area = 0;

        const auto ROW_SIZE = grid.size();
        for( SIZE_TYPE row=0; row<ROW_SIZE; ++row )
        {
            const auto COL_SIZE = grid.at(row).size();
            for( SIZE_TYPE col=0; col<COL_SIZE; ++col )
            {
                if( LAND == grid.at(row).at(col) )
                {
                    max_area = std::max( max_area, DFS( row, col, grid ) );
                }
            }
        }

        return max_area;
    }
};

