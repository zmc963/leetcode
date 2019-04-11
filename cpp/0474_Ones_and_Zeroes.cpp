class Solution
{
    using SIZE_TYPE = std::vector<std::string>::size_type;

public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        std::vector<std::vector<int>> dp( m+1, std::vector<int>(n+1, 0) );

        for( auto&& s : strs )
        {
            SIZE_TYPE count_0 = std::count( s.begin(), s.end(), '0' );
            auto count_1 = s.size() - count_0;

            for( SIZE_TYPE zero=m; zero>=count_0 && zero<=m; --zero )
            {
                for( SIZE_TYPE one=n; one>=count_1 && one<=n; --one )
                {
                    dp.at(zero).at(one) = std::max(dp.at(zero).at(one), dp.at(zero-count_0).at(one-count_1)+1 );
                }
            }
        }

        return dp.at(m).at(n);
    }
};
