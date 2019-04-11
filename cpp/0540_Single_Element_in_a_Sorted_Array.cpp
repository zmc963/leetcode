class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int singleNonDuplicate(vector<int>& nums)
    {
        if( nums.empty() ) return -1;

        const auto SIZE = nums.size();
        SIZE_TYPE left = 0;
        SIZE_TYPE right = SIZE - 1;

        while( right<SIZE && left<=right )
        {
            auto mid_idx = left + (right-left)/2;
            auto mid_val = nums.at(mid_idx);

            if( 0==(mid_idx+1)%2 && (left<mid_idx && mid_val==nums.at(mid_idx-1)) )
            {
                left = mid_idx + 1;
            }
            else if( 1==(mid_idx+1)%2 && (mid_idx<right && mid_val==nums.at(mid_idx+1)) )
            {
                left = mid_idx + 2;
            }
            else if( 0==(mid_idx+1)%2 && (mid_idx<right && mid_val==nums.at(mid_idx+1)) )
            {
                right = mid_idx - 1;
            }
            else if( 1==(mid_idx+1)%2 && (left<mid_idx && mid_val==nums.at(mid_idx-1)) )
            {
                right = mid_idx - 2;
            }
            else
            {
                assert( (mid_idx==right || (mid_idx<right && mid_val!=nums.at(mid_idx+1))) &&
                        (mid_idx==left || (left<mid_idx && mid_val!=nums.at(mid_idx-1))) );
                return mid_val;
            }
        }

        return -1;
    }
};
