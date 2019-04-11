class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

    vector<vector<VALUE_TYPE>>& m_rects;
    std::map<VALUE_TYPE, SIZE_TYPE> m_area_map;
    VALUE_TYPE m_total_points;

public:
    Solution(vector<vector<int>>& rects) :
         m_rects(rects)
        ,m_total_points(0)
    {
        const auto SIZE = m_rects.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            auto width = m_rects.at(i).at(2) - m_rects.at(i).at(0);
            auto height = m_rects.at(i).at(3) - m_rects.at(i).at(1);
            assert( width>=0 && height>=0 );

            m_total_points += (width+1) * (height+1);
            m_area_map.emplace( m_total_points, i );
        }
    }

    vector<int> pick()
    {
        if( m_rects.empty() ) return{};

        std::random_device rd;
        std::default_random_engine gen = std::default_random_engine(rd());
        std::uniform_int_distribution<int> dis_rect_idx(0, m_total_points);

        auto rect_idx = m_area_map.lower_bound( dis_rect_idx(gen) );
        assert( m_area_map.end() != rect_idx );
        auto&& chosen_rect = m_rects.at( rect_idx->second );

        auto width = chosen_rect.at(2) - chosen_rect.at(0);
        auto height = chosen_rect.at(3) - chosen_rect.at(1);
        assert( width>=0 && height>=0 );

        std::uniform_int_distribution<int> dis_width(0, width);
        std::uniform_int_distribution<int> dis_height(0, height);

        return { chosen_rect.at(0)+dis_width(gen), chosen_rect.at(1)+dis_height(gen) };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
