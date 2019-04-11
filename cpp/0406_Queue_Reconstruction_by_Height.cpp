class Solution
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
    {
        auto cmp = []( const auto& left, const auto& right )
        {
            if( left.first == right.first )
            {
                return left.second < right.second;
            }

            return left.first > right.first;
        };

        std::sort( people.begin(), people.end(), cmp );

        std::vector<std::pair<int, int>> ans;
        for( auto& p : people )
        {
            assert( p.second <= ans.size() );
            ans.insert( ans.begin()+p.second, p );
        }

        return ans;
    }
};
