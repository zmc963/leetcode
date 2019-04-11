class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        std::sort( houses.begin(), houses.end() );
        std::sort( heaters.begin(), heaters.end() );

        auto max_radius = 0;
        for( auto house_pos : houses )
        {
            auto rhs_itr = std::upper_bound( heaters.begin(), heaters.end(), house_pos );

            int curr_min_radius = std::numeric_limits<decltype(curr_min_radius)>::max();
            if( heaters.end() != rhs_itr )
            {
                curr_min_radius = std::abs( *rhs_itr - house_pos );
            }

            if( heaters.begin()!=rhs_itr && !heaters.empty() )
            {
                curr_min_radius = std::min( curr_min_radius, std::abs(*(rhs_itr-1) - house_pos) );
            }

            max_radius = std::max( max_radius, curr_min_radius );
        }

        return max_radius;
    }
};
