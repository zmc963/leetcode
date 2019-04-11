class Solution
{
    using SIZE_TYPE = std::vector<std::pair<int, int>>::size_type;

public:
    int numberOfBoomerangs(vector<pair<int, int>>& points)
    {
        const auto SIZE = points.size();
        SIZE_TYPE count = 0;
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            unordered_map<int, SIZE_TYPE> mapping;
            for( SIZE_TYPE j=0; j<SIZE; ++j )
            {
                auto x_diff = points.at(i).first - points.at(j).first;
                auto y_diff = points.at(i).second - points.at(j).second;
                ++mapping[x_diff*x_diff + y_diff*y_diff];
            }

            for( auto m : mapping )
            {
                count += m.second * (m.second-1);
            }
        }

        return count;
    }
};
