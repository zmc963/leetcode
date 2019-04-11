class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    string reverseStr(string s, int k)
    {
        const auto SIZE = s.size();
        for( SIZE_TYPE i=0; i<SIZE; i+=2*k )
        {
            SIZE_TYPE left = i;
            SIZE_TYPE right = std::min( i+k-1, SIZE-1 );

            while( right<SIZE && left<right )
            {
                std::swap( s.at(left++), s.at(right--) );
            }
        }

        return s;
    }
};
