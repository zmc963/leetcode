class Solution
{
     using SIZE_TYPE = std::vector<int>::size_type;

public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        std::unordered_map<int, SIZE_TYPE> hash{{0,-1}};
        const auto SIZE = nums.size();
        auto sum = 0;

        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            sum += nums.at(i);

            auto reamainder = k==0 ? sum : (sum%k);
            if( hash.count(reamainder) )
            {
                if( i - hash[reamainder] > 1 ) return true;
            }
            else
            {
                hash[reamainder] = i;
            }
        }

        return false;
    }
};
