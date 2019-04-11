class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int wiggleMaxLength(vector<int>& nums)
    {
	// this problem can be solved in O(n), here is an original O(n^2) solution
        const auto SIZE = nums.size();
        const auto DP_INIT_VAL = std::numeric_limits<SIZE_TYPE>::max();
        std::vector<SIZE_TYPE> dp_up(SIZE+1, DP_INIT_VAL);
        std::vector<SIZE_TYPE> dp_down(SIZE+1,  DP_INIT_VAL);

        SIZE_TYPE max_len = 0;
        for( SIZE_TYPE i=1; i<=SIZE; ++i )
        {
            auto target_num = nums.at(i-1);
            dp_up.at(i) = 1;
            dp_down.at(i) = 1;

            for( SIZE_TYPE j=1; j<i; ++j )
            {
                auto curr_num = nums.at(j-1);
                if( target_num > curr_num )
                {
                    dp_up.at(i) = std::max(dp_up.at(i), dp_down.at(j)+1);
                }
                else if( target_num < curr_num )
                {
                    dp_down.at(i) = std::max(dp_down.at(i), dp_up.at(j)+1);
                }
            }

            max_len = std::max( max_len, dp_up.at(i) );
            max_len = std::max( max_len, dp_down.at(i) );
        }

        // assert( max_len == 1 + std::max(dp_up.at(SIZE), dp_down.at(SIZE)));
        return max_len;
    }
};
