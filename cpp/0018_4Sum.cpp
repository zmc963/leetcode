class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        std::sort( nums.begin(), nums.end() );

        std::vector<std::vector<int>> ans;
        const auto SIZE = nums.size();
        for( std::vector<int>::size_type i=0; i<SIZE; )
        {
            auto a = nums.at(i);
            for( std::vector<int>::size_type j=i+1; j<SIZE; )
            {
                auto b = nums.at(j);
                auto curr_target = target-a-b;

                auto lo = j+1;
                auto hi = SIZE-1;

                while( lo < hi )
                {
                    auto c = nums.at(lo);
                    auto d = nums.at(hi);
                    auto curr_sum = c+d;

                    if( curr_target == curr_sum )
                    {
                        ans.push_back( {a, b, c, d} );

                        while( lo < hi && nums.at(lo) == c) lo++;
                        while( lo < hi && nums.at(hi) == d) hi--;
                    }
                    else if( curr_target < curr_sum ) --hi;
                    else ++lo;
                }

                while( (SIZE>j) && (b==nums.at(j)) ) ++j;
            }

            while( (SIZE>i) && (a==nums.at(i)) ) ++i;
        }

        return ans;
    }
};
