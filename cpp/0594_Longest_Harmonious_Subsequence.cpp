class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

public:
    int findLHS(vector<int>& nums)
    {
        std::map<VALUE_TYPE, SIZE_TYPE> mapping;

        for( auto n : nums ) ++mapping[n];

        SIZE_TYPE max_len = 0;
        for( auto&& m : mapping )
        {
            if( mapping.count( m.first+1 ) )
            {
                max_len = std::max( max_len, m.second + mapping[m.first+1] );
            }
        }

        return max_len;
    }
};


