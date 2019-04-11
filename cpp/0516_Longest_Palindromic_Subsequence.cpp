class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    int longestPalindromeSubseq(string s)
    {
        const auto SIZE = s.size();
        std::vector<SIZE_TYPE> dp( SIZE, 0 );

        for( SIZE_TYPE j=0; j<SIZE; ++j )
        {
            SIZE_TYPE pre_old = 0;
            auto old = dp;
            dp.at(j) = 1;
            for( SIZE_TYPE i=j-1; i<j; --i )
            {
                assert( j >= 1 );
                assert( i+1 <= j );

                auto old_dp_i = pre_old;
                pre_old = dp.at(i);

                if( s.at(i) == s.at(j) )
                {
                    dp.at(i) = old_dp_i + 2;
                }
                else
                {
                    dp.at(i) = std::max( dp.at(i+1), dp.at(i) );
                }
            }
        }

        return dp.at(0);
    }
};
