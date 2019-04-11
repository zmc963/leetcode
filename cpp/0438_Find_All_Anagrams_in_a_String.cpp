class Solution
{
    using SIZE_TYPE = std::string::size_type;
    using VALUE_TYPE = std::string::value_type;

public:
    vector<int> findAnagrams(string s, string p)
    {
        std::unordered_map<VALUE_TYPE, long long> hash;
        for( auto&& c : p ) ++hash[c];
        long long count_p = p.size();

        std::vector<int> anagrams;
        const auto SIZE = s.size();
        const auto ANAGRAM_SIZE = p.size();
        for( SIZE_TYPE left=0,right=0; right<SIZE; ++right )
        {
            auto c = s.at(right);
            if( hash.count(c) && hash[c]-- >= 1 ) --count_p;

            if( 0 == count_p ) anagrams.push_back(left);

            if( right-left+1 == ANAGRAM_SIZE )
            {
                auto c = s.at(left);
                if( hash.count(c) && hash[c]++ >= 0 ) ++count_p;

                ++left;
            }

            assert( right-left+1 <= ANAGRAM_SIZE );
        }

        return anagrams;
    }
};
