class Solution
{
    using IDX_TYPE = std::vector<int>::size_type;

    IDX_TYPE ExtremeSearchRange( vector<int>& nums, int target, bool is_left )
    {
        const auto SIZE = nums.size();

        IDX_TYPE left = 0;
        IDX_TYPE right = SIZE-1;

        IDX_TYPE curr_idx = SIZE;
        while( (right<SIZE) && (left<=right) )
        {
            auto mid_idx = left + (right-left) / 2;
            auto mid_val = nums.at(mid_idx);

            // std::cout << " " << nums.at(left)<< " " << mid_val<< " " << nums.at(right)<< std::endl;
            if( target > mid_val )
            {
                left = mid_idx + 1;
            }
            else if( target < mid_val )
            {
                right = mid_idx - 1;
            }
            else
            {
                curr_idx = mid_idx;
                if( is_left )
                {
                    right = mid_idx - 1;
                }
                else
                {
                    left = mid_idx + 1;
                }
            }
        }

        return curr_idx;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        const auto SIZE = nums.size();

        IDX_TYPE left = ExtremeSearchRange( nums, target, true );
        IDX_TYPE right = ExtremeSearchRange( nums, target, false );


        return { (left==SIZE)?-1:left, (right==SIZE)?-1:right };
    }
};
