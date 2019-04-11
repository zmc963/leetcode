class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    string licenseKeyFormatting(string S, int K)
    {
        std::string raw_S;
        for( auto c : S )
        {
            if( '-' != c ) raw_S += std::toupper(c);
        }

        const auto SIZE = raw_S.size();
        auto first_group_size = raw_S.size() % K;
        first_group_size = first_group_size==0? K : first_group_size;

        std::string ans = raw_S.substr( 0, first_group_size );

        for( SIZE_TYPE i=first_group_size; i<SIZE; i+=K )
        {
            ans += '-' + raw_S.substr( i, K );
        }

        return ans;
    }
};
