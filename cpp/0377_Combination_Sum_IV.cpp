class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int combinationSum4(vector<int>& nums, int target)
    {
        const auto SIZE = nums.size();
        const auto DP_INIT_VAL = 0;
        std::vector<unsigned> dp(target+1, DP_INIT_VAL);
        dp.front() = 1;

        for( SIZE_TYPE i=1; i<=target; ++i )
        {
            for( auto num : nums )
            {
                dp.at(i) += i>=i-num ? dp.at(i-num) : 0;
            }
        }

        return dp.back(); // unsigned to signed => implementation defined behavior...
    }
};
