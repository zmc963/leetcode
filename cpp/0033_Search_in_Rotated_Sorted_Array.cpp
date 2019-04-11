class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        using IDX_TYPE = std::vector<int>::size_type;

        const auto SIZE = nums.size();
        IDX_TYPE left = 0;
        IDX_TYPE right = SIZE-1;
        while( (right<SIZE) && (left <= right) )
        {
            auto mid_idx = left + (right-left) / 2;
            auto mid_val = nums.at(mid_idx);

            // std::cout << nums.at(left) << " " << mid_val << " "<< nums.at(right) << std::endl;
            if( mid_val > target )
            {
                auto right_val = nums.at(right);
                if( (target<=right_val) && (mid_val>right_val) )
                {
                    left = mid_idx + 1;
                }
                else
                {
                    right = mid_idx - 1;
                }
            }
            else if( mid_val < target )
            {
                auto right_val = nums.at(right);
                if( (target>right_val) && (mid_val<=right_val) )
                {
                    right = mid_idx - 1;
                }
                else
                {
                    left = mid_idx + 1;
                }
            }
            else
            {
                return mid_idx;
            }
        }

        return -1;
    }
};
