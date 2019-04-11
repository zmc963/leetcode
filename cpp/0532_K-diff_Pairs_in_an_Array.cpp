class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int findPairs(vector<int>& nums, int k)
    {
        if( nums.empty() ) return 0;

        std::sort( nums.begin(), nums.end() );

        auto cnt = 0;
        const auto SIZE = nums.size();
        for( SIZE_TYPE i=0; i<SIZE; )
        {
            auto target = nums.at(i) + k;
            auto found_left = std::lower_bound( nums.begin()+i+1, nums.end(), target );
            if( nums.end() == found_left ) break;
            if( *found_left == target ) ++cnt;

            auto curr = i++;
            while( i<SIZE && nums.at(curr)==nums.at(i) ) ++i;
        }

        return cnt;
    }
};
