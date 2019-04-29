class Solution
{
    using VALUE_TYPE = std::pair<int, int>;
    using SIZE_TYPE = std::vector<VALUE_TYPE>::size_type;

public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        std::vector<VALUE_TYPE> pair;
        for( auto&& p : pairs ) pair.emplace_back( p.front(), p.back() );

        // either sort by start or end is okay
        std::sort( pair.begin(), pair.end(), [] ( const auto& left, const auto& right )
            {
                return left.first==right.first ? left.second<right.second : left.first<right.first;
            });

        std::vector<VALUE_TYPE> dp;

        for( auto&& p : pair )
        {
            if( dp.empty() )
            {
                dp.push_back(p);
            }
            else
            {
                auto found = std::lower_bound( dp.begin(), dp.end(), p.first, [] ( const auto& left, const auto& target )
                    {
                        return left.second < target;
                    });

                if( dp.end() == found )
                {
                    dp.push_back(p);
                }
                else if( found->second > p.second )
                {
                    *found = p;
                }
            }
        }

        return dp.size();
    }
};
