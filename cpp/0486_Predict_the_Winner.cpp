class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    int PredictTheWinnerImp( const std::vector<int>& nums, SIZE_TYPE left, SIZE_TYPE right, std::vector<std::vector<int>>& memo ) const
    {
        assert( left < nums.size() );
        assert( right < nums.size() );

        if( memo.at(left).at(right) ) return memo.at(left).at(right);

        auto sum = std::accumulate( nums.begin()+left, nums.begin()+right+1, 0 );

        memo.at(left).at(right) = left==right ?
                  nums.at(left) :
                  std::max( sum - PredictTheWinnerImp( nums, left+1, right, memo ),
                            sum - PredictTheWinnerImp( nums, left, right-1, memo ) );

        return memo.at(left).at(right);
    }

public:
    bool PredictTheWinner( std::vector<int>& nums )
    {
        if( nums.size() <= 1 ) return true;

        const auto SIZE = nums.size();
        std::vector<std::vector<int>> memo( SIZE+1, std::vector<int>(SIZE+1, 0) );

        return PredictTheWinnerImp( nums, 0, SIZE-1, memo )*2 >= std::accumulate( nums.begin(), nums.end(), 0 );
    }
};
