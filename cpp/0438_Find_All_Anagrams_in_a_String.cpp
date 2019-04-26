class Solution
{
    using SIZE_TYPE = std::string::size_type;
    using VALUE_TYPE = std::string::value_type;

public:
    std::vector<int> findAnagrams(string s, string p)
    {
        std::unordered_map<VALUE_TYPE, SIZE_TYPE> p_hash;
        for( auto&& c : p ) ++p_hash[c];

        std::vector<int> anagrams;
        const auto S_SIZE = s.size();
        const auto P_SIZE = p.size();
        for( SIZE_TYPE left=0, right=0; right<S_SIZE; ++right )
        {
            auto c = s.at(right);
            if( !p_hash.count(c) || 0==p_hash[c] )
            {
                while( c != s.at(left) )
                {
                    assert( p_hash.count(s.at(left)) );
                    ++p_hash[s.at(left)];
                    ++left;
                }
                assert( left <= right );
                ++left;
            }
            else
            {
                --p_hash[c];
                if( P_SIZE == right-left+1 )
                {
                    anagrams.push_back(left);
                    ++p_hash[s.at(left++)];
                }
            }
        }

        return anagrams;
    }
};
