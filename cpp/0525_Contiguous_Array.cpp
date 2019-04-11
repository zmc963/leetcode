class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int findMaxLength( std::vector<int>& nums )
    {
        std::unordered_map<int, SIZE_TYPE> hash{{0, -1}};
        const auto SIZE = nums.size();

        auto sum = 0;
        SIZE_TYPE max_len = 0;
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            sum += (nums[i] << 1) - 1;

            if( hash.count(sum) )
            {
                max_len = std::max( max_len, i - hash[sum] );
            }
            else
            {
                hash[sum] = i;
            }
        }

        return max_len;
    }
};
