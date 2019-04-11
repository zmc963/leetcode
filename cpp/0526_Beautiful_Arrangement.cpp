class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    void Permutation( SIZE_TYPE start, std::vector<int>& nums, int& cnt ) const
    {
        if( start == nums.size() )
        {
            ++cnt;
            return;
        }

        const auto SIZE = nums.size();
        for( SIZE_TYPE i=start; i<SIZE; ++i )
        {
            if( 0!=(start+1)%nums.at(i) && 0!=nums.at(i)%(start+1) ) continue;

            std::swap( nums.at(i), nums.at(start) );

            Permutation( start+1, nums, cnt );

            std::swap( nums.at(start), nums.at(i) );
        }
    }


public:
    int countArrangement(int N)
    {
        std::vector<int> nums;
        for( auto i=1; i<=N; ++i ) nums.push_back(i);

        auto cnt = 0;
        Permutation( 0, nums, cnt );

        return cnt;
    }
};
