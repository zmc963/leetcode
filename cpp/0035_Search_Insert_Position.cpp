class Solution
{
    using IDX_TYPE = std::vector<int>::size_type;

public:
    int searchInsert(vector<int>& nums, int target)
    {
        const auto SIZE = nums.size();

        IDX_TYPE left = 0;
        IDX_TYPE right = SIZE-1;

        IDX_TYPE leftmost_idx = SIZE;
        while( (right<SIZE) && (left<=right) )
        {
            auto mid_idx = left + (right-left) / 2;
            auto mid_val = nums.at(mid_idx);

            std::cout << left << " " << mid_idx << " " << right << std::endl;

            if( target < mid_val )
            {
                right = mid_idx - 1;
            }
            else if( target > mid_val )
            {
                left = mid_idx + 1;
            }
            else
            {
                leftmost_idx = mid_idx;

                right = mid_idx - 1;
            }
        }

        return  (leftmost_idx==SIZE) ? left : leftmost_idx;
    }
};
