class Solution
{
    using SIZE_TYPE = std::string::size_type;

    bool IsBSubstringOfA( const std::string& B, const std::string& A ) const
    {
        const auto SIZE_A = A.size();
        const auto SIZE_B = B.size();
        for( SIZE_TYPE i=0; i<SIZE_A; ++i )
        {
            auto j = i;
            while( j<SIZE_A && j-i<SIZE_B && A.at(j)==B.at(j-i) )
            {
                ++j;
            }

            if( j-i == SIZE_B ) return true;
        }

        return false;
    }

public:
    int repeatedStringMatch(string A, string B)
    {
        const auto SIZE_A = A.size();
        const auto SIZE_B = B.size();

        auto min_step = SIZE_B / SIZE_A + (0!=SIZE_B%SIZE_A);

        std::string new_A;
        for( auto i=0; i<min_step; ++i ) new_A += A;

        if( IsBSubstringOfA( B, new_A ) ) return min_step;
        else if( IsBSubstringOfA( B, new_A+A ) ) return min_step+1;

        return -1;
    }
};
