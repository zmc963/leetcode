class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    bool repeatedSubstringPattern(string s)
    {
        const auto SIZE = s.size();

        std::string pattern;
        for( SIZE_TYPE len=1; len<=SIZE/2; ++len )
        {
            pattern += s.at(len-1);
            if( 0 != SIZE % len ) continue;

            SIZE_TYPE j = len;
            for( ; j<SIZE; j+=len )
            {
                if( pattern != s.substr(j, len) ) break;
            }
            if( j == SIZE ) return true;
        }

        return false;
    }
};
