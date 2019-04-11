class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    int firstUniqChar(string s)
    {
        std::unordered_map<std::string::value_type, SIZE_TYPE> hash;
        for( auto& c : s ) ++hash[c];

        const auto SIZE = s.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            if( 1 == hash[s.at(i)] )
            {
                return i;
            }
        }

        return -1;
    }
};
