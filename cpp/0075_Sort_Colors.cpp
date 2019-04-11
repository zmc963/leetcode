class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    void sortColors(vector<int>& nums)
    {
        if( nums.empty() ) return;

        int pivot = 1;
        const auto SIZE = nums.size();
        for( SIZE_TYPE red=0, i=0, blue=SIZE-1; blue<SIZE && i<=blue; )
        {
            auto curr_num = nums.at(i);
            if( curr_num > pivot )
            {
                std::swap( nums.at(i), nums.at(blue) );
                --blue;
            }
            else if( curr_num < pivot )
            {
                std::swap( nums.at(i), nums.at(red) );
                ++red;
                ++i;
            }
            else
            {
                ++i;
            }
        }
    }
};
