class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int arrayPairSum(vector<int>& nums)
    {
        std::sort( nums.begin(), nums.end() );

        auto ans = 0;
        const auto SIZE = nums.size();

        for( SIZE_TYPE i=0; i<SIZE; i+=2 )
        {
            ans += nums.at(i);
        }

        return ans;
    }
};
