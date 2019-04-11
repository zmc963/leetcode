class Solution
{
    using SIZE_TYPE = std::string::size_type;
    using VALUE_TYPE = std::string::value_type;

public:
    int longestPalindrome(string s)
    {
        std::unordered_map<VALUE_TYPE, SIZE_TYPE> hash;
        for( auto c : s ) ++hash[c];

        int count = 0;
        for( auto h : hash ) count += (h.second/2) * 2;

        return s.size()>count ? count+1 : count;
    }
};
