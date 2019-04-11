class Solution
{
    using SIZE_TYPE = std::string::size_type;
    using VALUE_TYPE = std::string::value_type;

public:
    bool checkInclusion(string s1, string s2)
    {
        std::unordered_map<VALUE_TYPE, int> s1_hash;
        for( auto c : s1 ) ++s1_hash[c];

        const auto S1_SIZE = s1.size();
        const auto S2_SIZE = s2.size();
        for( SIZE_TYPE left=0, right=0; right<S2_SIZE; ++right )
        {
            auto c = s2.at(right);
            if( !s1_hash.count(c) || 0==s1_hash[c] )
            {
                while( c != s2.at(left) )
                {
                    assert( s1_hash.count(s2.at(left)) );
                    ++s1_hash[s2.at(left)];
                    ++left;
                }
                assert( left <= right );
                ++left;
            }
            else
            {
                --s1_hash[c];
                if( S1_SIZE == right-left+1 ) return true;
            }
        }

        return false;
    }
};
