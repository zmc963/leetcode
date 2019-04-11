class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int subarraySum( std::vector<int>& nums, int k )
    {
        const auto SIZE = nums.size();

        std::unordered_map<int, int> hash{{0, 1}};
        auto curr_sum = 0;
        auto cnt = 0;
        for( auto n : nums )
        {
            curr_sum += n;
            cnt += hash[curr_sum-k];

            ++hash[curr_sum];
        }

        return cnt;
    }
};
