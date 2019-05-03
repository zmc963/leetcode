class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    bool checkValidString(string s)
    {
        // lowest/highest # of expected ')'
        SIZE_TYPE lo = 0;
        SIZE_TYPE hi = 0;

        for( auto c : s )
        {
            assert( lo <= hi );
            if( '(' == c )
            {
                ++lo;
                ++hi;
            }
            else if( ')' == c )
            {
                if( 0 == hi ) return false;
                if( 1 <= lo ) --lo;
                --hi;
            }
            else if( '*' == c )
            {
                if( 1 <= lo ) --lo;
                ++hi;
            }

        }

        return 0 == lo;
    }
};
