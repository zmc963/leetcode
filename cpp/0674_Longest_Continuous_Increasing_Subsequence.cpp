class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        const auto SIZE = nums.size();

        SIZE_TYPE max_len = 0;
        SIZE_TYPE curr_len = 0;
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            if( i==0 || nums.at(i)>nums.at(i-1) ) ++curr_len;
            else curr_len = 1;

            max_len = std::max( max_len, curr_len );
        }

        return max_len;
    }
};
