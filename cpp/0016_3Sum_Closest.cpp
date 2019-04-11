class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        std::sort( nums.begin(), nums.end() );

        int closest_offset = std::numeric_limits<decltype(closest_offset)>::max();
        int closest_sum = 0;

        const auto SIZE = nums.size();
        for( std::vector<int>::size_type i=0; i<SIZE; )
        {
            auto a = nums.at(i);
            auto remaining = target-a;

            auto lo = i+1;
            auto hi = SIZE-1;

            while( lo < hi )
            {
                auto b = nums.at(lo);
                auto c = nums.at(hi);
                auto sum = b+c;

                if( remaining == sum )
                {
                    return target;
                    // while( lo < hi && nums.at(lo) == b) lo++;
                    // while( lo < hi && nums.at(hi) == c) hi--;
                }
                else if( remaining < sum ) --hi;
                else ++lo;

                // std::cout << a <<" " << b << " " << c << std::endl;
                auto offset = std::abs(remaining-sum);
                if( closest_offset > offset )
                {
                    closest_offset  = offset;
                    closest_sum = a+sum;
                }
            }

            // jump to next value different from a
            while( (SIZE>i) && (a==nums.at(i)) ) ++i;
        }

        return closest_sum;
    }
};
