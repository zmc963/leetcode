class Solution
{
    using SIZE_TYPE = std::vector<std::pair<int, int>>::size_type;

public:
    int findMinArrowShots(vector<pair<int, int>>& points)
    {
        std::sort( points.begin(), points.end(), []( const auto& left, const auto& right )
            {
                return left.second==right.second ? left.first<right.first : left.second<right.second;
            });

        const auto SIZE = points.size();
        SIZE_TYPE count = 0;
        for( SIZE_TYPE left=0; left<SIZE; ++count )
        {
            auto right = left + 1;
            while( right<SIZE && points.at(left).second>=points.at(right).first )
            {
                ++right;
            }
            left = right;
        }

        return count;
    }
};
