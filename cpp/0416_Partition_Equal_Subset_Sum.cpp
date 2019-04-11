class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    // TLE
    bool CombinationSum( const std::vector<int>& nums, int targetSum, int startIdx, int currSum ) const
    {
        const auto SIZE = nums.size();
        assert( startIdx <= SIZE );

        if( startIdx==SIZE || targetSum<=currSum )
        {
            return targetSum==currSum;
        }

        for( SIZE_TYPE i=startIdx; i<SIZE; ++i )
        {
            if( CombinationSum( nums, targetSum, i+1, currSum+nums.at(i) ) )
            {
                return true;
            }
        }

        return false;
    }

public:
    bool canPartition( const std::vector<int>& nums )
    {
        auto sum = std::accumulate( nums.begin(), nums.end(), 0 );

        if( 0 == sum % 2 )
        {
            auto target_sum = sum / 2;
            std::vector<bool> dp( target_sum+1, false );
            dp.front() = true;

            const auto SIZE = dp.size();
            for( auto curr_num : nums )
            {
                for( SIZE_TYPE j=SIZE-1; j>=curr_num&&j<SIZE; --j )
                {
                    dp.at(j) = dp.at(j) || dp.at(j-curr_num);
                }
            }

            return dp.back();
        }

        return false;

        // return sum%2==0 && CombinationSum( nums, sum/2, 0, 0 );
    }
};
