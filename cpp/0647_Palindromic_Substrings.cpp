class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    int countSubstrings(string s)
    {
        const auto SIZE = s.size();
        SIZE_TYPE cnt = 0;
        std::vector<std::vector<SIZE_TYPE>> dp( SIZE+1, std::vector<SIZE_TYPE>( SIZE+1, 0 ) );

        for( SIZE_TYPE j=1; j<=SIZE; ++j )
        {
            dp.at(j).at(j) = 1;
            for( SIZE_TYPE i=j; i>=1; --i )
            {
                if( s.at(i-1) == s.at(j-1) )
                {
                    if( i+1<=j-1 && 0<dp.at(i+1).at(j-1) )
                    {
                        dp.at(i).at(j) = dp.at(i+1).at(j-1) + 2;
                    }
                    else if( 1 == j-i )
                    {
                        dp.at(i).at(j) = 2;
                    }
                }

                if( 0 < dp.at(i).at(j) ) ++cnt;
            }
        }

        return cnt;
    }
};
