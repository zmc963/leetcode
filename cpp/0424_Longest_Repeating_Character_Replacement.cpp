class Solution
{
    using SIZE_TYPE = std::string::size_type;
    using VALUE_TYPE = std::string::value_type;

public:
    int characterReplacement(string s, int k)
    {
        std::unordered_map<VALUE_TYPE, SIZE_TYPE> count;

        const auto SIZE = s.size();
        SIZE_TYPE max_len = 0;
        for( SIZE_TYPE left=0, right=0, curr_max_count=0; right<SIZE; ++right )
        {
            curr_max_count = std::max( curr_max_count, ++count[s.at(right)] );

            if( right-left+1 - curr_max_count > k )
            {
                if( curr_max_count == count[s.at(left)] )
                {
                    --curr_max_count;
                }

                --count[s.at(left)];
                ++left;
            }

            max_len = std::max( max_len, right-left+1 );
        }

        return max_len;
    }
};
