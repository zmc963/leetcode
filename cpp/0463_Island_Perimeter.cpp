class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        if( grid.empty() || grid.front().empty() ) return 0;

        const auto ROW_SIZE = grid.size();
        const auto COL_SIZE = grid.front().size();
        const auto LAND = 1;

        SIZE_TYPE perimeter = 0;
        for( SIZE_TYPE row=0; row<ROW_SIZE; ++row )
        {
            for( SIZE_TYPE col=0; col<COL_SIZE; ++col )
            {
                if( LAND == grid.at(row).at(col) )
                {
                    perimeter += row+1<ROW_SIZE && LAND!=grid.at(row+1).at(col);
                    perimeter += row>0 && LAND!=grid.at(row-1).at(col);
                    perimeter += 0==row;
                    perimeter += ROW_SIZE-1==row;

                    perimeter += col+1<COL_SIZE && LAND!=grid.at(row).at(col+1);
                    perimeter += col>0 && LAND!=grid.at(row).at(col-1);
                    perimeter += 0==col;
                    perimeter += COL_SIZE-1==col;
                }
            }
        }


        return perimeter;
    }
};

