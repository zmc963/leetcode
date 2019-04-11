class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int nextGreaterElement( int n )
    {
        // or using std::string digits = std::to_string(n);
        std::vector<int> digits;
        bool is_negative = n < 0;

        while( 0 != n )
        {
            digits.push_back( std::abs(n%10) );
            n /= 10;
        }

        const auto SIZE = digits.size();
        for( SIZE_TYPE i=1; i<SIZE; ++i )
        {
            if( (!is_negative && digits.at(i)<digits.at(i-1)) ||
                (is_negative && digits.at(i)>digits.at(i-1)))
            {
                auto found = is_negative ?
                    --std::lower_bound( digits.begin(), digits.begin()+i, digits.at(i) ) :
                    std::upper_bound( digits.begin(), digits.begin()+i, digits.at(i) );
                assert( digits.begin()+i != found );

                std::swap( digits.at(i), *found );
                std::reverse( digits.begin(), digits.begin()+i );

                auto ans = 0;
                const auto BASE = 10;
                for( SIZE_TYPE i=SIZE-1; i<SIZE; --i )
                {
                    if( ((std::numeric_limits<int>::max()-digits.at(i))/BASE) < ans ) return -1;
                    ans = BASE*ans + digits.at(i);
                }

                // return is_negative ? -ans : ans;
                return is_negative ? -1 : ans; // by problem definition
            }
        }

        return -1;
    }
};
