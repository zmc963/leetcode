class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    bool CombinationSum(
        const std::vector<int>& nums,
        int targetSum,
        SIZE_TYPE currIdx,
        std::vector<int>& visitedSum ) const
    {
        assert( currIdx <= nums.size() );

        if( currIdx == nums.size() )
        {
            for( auto sum : visitedSum )
            {
                if( targetSum != sum ) return false;
            }

            return true;
        }

        const auto SIZE = nums.size();
        for( auto& sum : visitedSum )
        {
            sum += nums.at(currIdx);
            if( sum<=targetSum && CombinationSum( nums, targetSum, currIdx+1, visitedSum ) )
            {
                return true;
            }
            sum -= nums.at(currIdx);
        }

        return false;
    }

public:
    bool makesquare(vector<int>& nums)
    {
        auto sum = std::accumulate( nums.begin(), nums.end(), 0 );
        if( 0==sum || 0!=sum%4 ) return false;

        std::vector<int> visited_sum( 4, 0 );
        auto target_sum = sum / 4;

        // O(4^n)
        // sort( nums.rbegin(), nums.rend() );
        // return CombinationSum( nums, target_sum, 0, visited_sum );

        // O(n 2^n)
        const auto SIZE = nums.size();
        int max_state = (0x01 << SIZE) - 1;
        std::vector<int> candidate_state;
        std::unordered_set<int> valid_half;

        for( int curr_state=1; curr_state<=max_state; ++curr_state )
        {
            auto curr_state_sum = 0;
            for( SIZE_TYPE i=0; i<SIZE; ++i )
            {
                if( curr_state & (0x01<<i) )
                {
                    curr_state_sum += nums.at(i);
                }
            }

            if( curr_state_sum == target_sum )
            {
                for( auto past_state : candidate_state )
                {
                    if( 0 == (past_state & curr_state) )
                    {
                        auto half = past_state | curr_state;
                        if( valid_half.count( half ^ max_state ) ) return true;

                        valid_half.insert(half);
                    }
                }

                candidate_state.push_back( curr_state );
            }
        }

        return false;
    }
};
