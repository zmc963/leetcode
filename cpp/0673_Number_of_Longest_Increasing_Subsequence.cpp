class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int findNumberOfLIS(vector<int>& nums)
    {
        const auto SIZE = nums.size();
        std::vector<std::pair<SIZE_TYPE, SIZE_TYPE>> dp( SIZE+1 );

        SIZE_TYPE max_len = 0;
        SIZE_TYPE cnt = 0;
        for( SIZE_TYPE j=1; j<=SIZE; ++j )
        {
            auto curr_num = nums.at(j-1);
            dp.at(j) = {1, 1};
            for( SIZE_TYPE i=j-1; i>=1; --i )
            {
                if( nums.at(i-1) < curr_num )
                {
                    auto new_len = dp.at(i).first + 1;
                    if( dp.at(j).first < new_len )
                    {
                        dp.at(j) = { new_len, dp.at(i).second };
                    }
                    else if( dp.at(j).first == new_len )
                    {
                        dp.at(j).second += dp.at(i).second;
                    }
                }
            }

            if( dp.at(j).first > max_len )
            {
                max_len = dp.at(j).first;
                cnt = dp.at(j).second;
            }
            else if( dp.at(j).first == max_len )
            {
                cnt += dp.at(j).second;
            }
        }

        // std::cout << max_len << std::endl;
        return cnt;
    }
};
