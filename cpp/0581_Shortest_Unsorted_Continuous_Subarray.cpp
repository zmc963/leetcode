class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        const auto SIZE = nums.size();

        SIZE_TYPE left_idx = SIZE;
        SIZE_TYPE right_idx = 0;
        auto min_val = std::numeric_limits<VALUE_TYPE>::max();
        auto max_val = std::numeric_limits<VALUE_TYPE>::min();
        for( SIZE_TYPE i=1; i<SIZE; ++i )
        {
            auto curr = nums.at(i);
            auto prev = nums.at(i-1);

            if( prev > curr )
            {
                left_idx = std::min( left_idx, i-1 );
                right_idx = i;

                min_val = std::min( min_val, curr );
                max_val = std::max( max_val, prev );
            }
        }

        // all ascending or empty
        if( 0 == right_idx ) return 0;

        assert( left_idx <= right_idx );
        assert( min_val <= max_val );

        auto max_found = std::lower_bound( nums.begin()+right_idx+1, nums.end(), max_val );
        if( nums.end() != max_found )
        {
            right_idx = --max_found - nums.begin();
        }
        else
        {
            right_idx = SIZE - 1;
        }

        auto last = nums.begin() + left_idx;
        auto min_found = std::upper_bound( nums.begin(), last, min_val );
        if( last != min_found )
        {
            left_idx = min_found - nums.begin();
        }

        return right_idx - left_idx + 1;
    }
};
