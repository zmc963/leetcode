class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int countBattleships(vector<vector<char>>& board)
    {
        if( board.empty() || board.front().empty() ) return 0;

        const auto ROW_SIZE = board.size();
        const auto COL_SIZE = board.front().size();

        int count = 0;
        for( SIZE_TYPE row=0; row<ROW_SIZE; ++row )
        {
            for( SIZE_TYPE col=0; col<COL_SIZE; ++col )
            {
                if( 'X'==board.at(row).at(col) )
                {
                    bool up = (row>=1 && 'X'!=board.at(row-1).at(col)) || row==0;
                    bool left = (col>=1 && 'X'!=board.at(row).at(col-1)) || col==0;

                    count += up && left;
                }
            }
        }

        return count;
    }
};
