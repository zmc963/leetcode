class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int findDuplicate(vector<int>& nums)
    {
        const auto SIZE = nums.size();

        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            auto curr_num = std::abs(nums.at(i));
            assert( curr_num < SIZE );

            if( nums.at(curr_num) < 0 )
            {
                return curr_num;
            }

            nums.at(curr_num) = -nums.at(curr_num);
        }

        return -1;
    }
};
