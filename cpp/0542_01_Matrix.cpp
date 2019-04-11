class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
    {
        if( matrix.empty() || matrix.front().empty() ) return {};

        const auto ROW_SIZE = matrix.size();
        const auto COL_SIZE = matrix.front().size();

        std::vector<std::vector<int>> ans( ROW_SIZE, std::vector<int>(COL_SIZE, std::numeric_limits<VALUE_TYPE>::max()) );
        std::queue<std::pair<SIZE_TYPE, SIZE_TYPE>> curr_slots;

        for( SIZE_TYPE row=0; row<ROW_SIZE; ++row )
        {
            for( SIZE_TYPE col=0; col<COL_SIZE; ++col )
            {
                if( 0 == matrix.at(row).at(col) )
                {
                    curr_slots.emplace( row, col );
                    ans.at(row).at(col) = 0;
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while( !curr_slots.empty() )
        {
            auto curr = curr_slots.front();
            curr_slots.pop();

            auto row = curr.first;
            auto col = curr.second;
            auto new_dist = ans.at(row).at(col) + 1;

            for( auto&& d : dir )
            {
                auto new_row = row + d[0];
                auto new_col = col + d[1];

                if( new_row<ROW_SIZE && new_col<COL_SIZE && new_dist<ans.at(new_row).at(new_col) )
                {
                    ans.at(new_row).at(new_col) = new_dist;
                    curr_slots.emplace( new_row, new_col );
                }
            }
        }

        return ans;
    }
};
