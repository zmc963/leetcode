class Solution
{
    using SIZE_TYPE = std::string::size_type;
    using VALUE_TYPE = std::string::value_type;

    // [left, right)
    SIZE_TYPE LongestSubstringImp( const std::string& s, int k, SIZE_TYPE start, SIZE_TYPE end ) const
    {
        assert( start <= s.size() && end <= s.size() && end >= start );

        if( end - start < k ) return 0;

        std::unordered_map<VALUE_TYPE, SIZE_TYPE> hash;
        for( SIZE_TYPE i=start; i<end; ++i ) ++hash[s.at(i)];

        auto isValid = []( const auto& hash, auto k, auto c )
        {
            return hash.count(c) && hash.at(c) >= k;
        };

        SIZE_TYPE max_len = 0;
        for( SIZE_TYPE left=start; left<end; ++left )
        {
            if( isValid(hash, k, s.at(left))  )
            {
                auto right = left+1;
                while( right<end && isValid(hash, k, s.at(right)) ) ++right;

                if( left==start && right==end ) return right-left;

                max_len = std::max( max_len, LongestSubstringImp( s, k, left, right ) );
                left = right-1;
            }
        }

        return max_len;
    }

public:
    int longestSubstring(string s, int k)
    {
        assert( k >= 0 );

        return LongestSubstringImp( s, k, 0, s.size() );
    }
};
