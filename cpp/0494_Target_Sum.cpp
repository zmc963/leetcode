class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    int FindTargetSumWaysImp(
        const std::vector<int>& nums,
        SIZE_TYPE start,
        int currSum,
        int S,
        int& ans,
        std::vector<std::unordered_map<int, int>>& dp ) const
    {
        assert( start <= nums.size() );

        if( start == nums.size() )
        {
            if( S == currSum ) return 1;
            return 0;
        }
        else if( dp[start].count(currSum) )
        {
            return dp[start].at(currSum);
        }

        auto sum = FindTargetSumWaysImp( nums, start+1, currSum+nums.at(start), S, ans, dp ) +
                   FindTargetSumWaysImp( nums, start+1, currSum-nums.at(start), S, ans, dp );

        dp[start][currSum] = sum;
        return sum;
    }

public:
    int findTargetSumWays( std::vector<int>& nums, int S )
    {
        // top-down DP
        // int ans = 0;
        // std::vector<std::unordered_map<int, int>> dp( nums.size() );
        // return FindTargetSumWaysImp( nums, 0, 0, S, ans, dp );

        // bottom-up DP
        std::unordered_map<int, int> dp;
        dp[0] = 1;

        const auto SIZE = nums.size();
        for( auto curr_num : nums )
        {
            std::unordered_map<int, int> new_dp;
            for( auto& curr : dp )
            {
                auto curr_sum = curr.first;
                auto curr_count = curr.second;

                new_dp[curr_sum + curr_num] += curr_count;
                new_dp[curr_sum - curr_num] += curr_count;
            }

            dp.swap(new_dp);
        }

        return dp[S]; // return 0 by default, it's very convenient
    }
};
