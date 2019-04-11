class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    bool checkRecord(string s)
    {
        SIZE_TYPE A_cnt = 0;
        SIZE_TYPE L_continuous_cnt = 0;
        const auto SIZE = s.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            auto c = s.at(i);

            if( 'L' == c )
            {
                ++L_continuous_cnt;
            }
            else
            {
                if( 'A' == c ) ++A_cnt;

                L_continuous_cnt = 0;
            }

            if( 2<=A_cnt || 3<=L_continuous_cnt ) return false;
        }

        return true;
    }
};
