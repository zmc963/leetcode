class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int arrayNesting(vector<int>& nums)
    {

        const auto SIZE = nums.size();
        const auto MARKED = SIZE;
        SIZE_TYPE max_jump = 0;
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            if( MARKED == nums.at(i) ) continue;

            SIZE_TYPE local_max_jump = 0;
            int curr_idx = i;
            while( MARKED != nums.at(curr_idx) )
            {
                ++local_max_jump;

                auto temp_idx = curr_idx;
                curr_idx = nums.at(curr_idx);
                nums.at(temp_idx) = MARKED;
            }

            max_jump = std::max( max_jump, local_max_jump );
        }

        return max_jump;
    }
};
