class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
    {
        if( nums.empty() || nums.front().empty() ) return {};

        const auto ROW_SIZE = nums.size();
        const auto COL_SIZE = nums.front().size();

        if( ROW_SIZE*COL_SIZE != r*c ) return nums;

        std::vector<std::vector<int>> new_nums( r, std::vector<int>( c, 0 ) );
        SIZE_TYPE idx = 0;
        for( SIZE_TYPE row=0; row<ROW_SIZE; ++row )
        {
            for( SIZE_TYPE col=0; col<COL_SIZE; ++col )
            {
                new_nums.at(idx/c).at(idx%c) = nums.at(row).at(col);
                ++idx;
            }
        }

        return new_nums;
    }
};
