class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    struct BrickInfo
    {
        int m_x_pos = 0;
        SIZE_TYPE m_row = 0;
        SIZE_TYPE m_col = 0;

        BrickInfo() {}

        BrickInfo( int x_pos, SIZE_TYPE row, SIZE_TYPE col ) :
             m_x_pos(x_pos)
            ,m_row(row)
            ,m_col(col)
        {}
    };

    using CONTIANER_TYPE = std::vector<BrickInfo>;
    using VALUE_TYPE = CONTIANER_TYPE::value_type;

    struct PQComp
    {
        bool operator()( const BrickInfo& left, const BrickInfo& right ) const
        {
            return left.m_x_pos==right.m_x_pos ? left.m_row<right.m_row : left.m_x_pos>right.m_x_pos;
        }
    };

public:
    int leastBricks(vector<vector<int>>& wall)
    {
        const auto SIZE = wall.size();

        // hash table
        SIZE_TYPE max_bricks = 0;
        std::unordered_map<int, SIZE_TYPE> hash;
        for( auto& row : wall )
        {
            if( row.empty() ) continue;

            auto x_pos = 0;
            for( SIZE_TYPE col=0; col<row.size()-1; ++col )
            {
                x_pos += row.at(col);
                ++hash[x_pos];

                max_bricks = std::max( max_bricks, hash[x_pos] );
            }
        }

        return SIZE - max_bricks;



        // priority queue
        std::priority_queue<VALUE_TYPE, CONTIANER_TYPE, PQComp> curr_bricks;

        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            if( !wall.at(i).empty() ) curr_bricks.emplace( wall.at(i).front(), i, 0 );
        }

        auto min_crossed_num_bricks = SIZE;
        while( !curr_bricks.empty() )
        {
            auto curr_crossed_num_bricks = curr_bricks.size();
            assert( curr_crossed_num_bricks >= 1 );

            auto target_x_pos = curr_bricks.top().m_x_pos;
            do
            {
                auto target_brick = curr_bricks.top();
                curr_bricks.pop();
                --curr_crossed_num_bricks;

                if( target_brick.m_col+1 < wall.at(target_brick.m_row).size() )
                {
                    VALUE_TYPE next_brick;

                    next_brick.m_row = target_brick.m_row;
                    next_brick.m_col = target_brick.m_col + 1;
                    next_brick.m_x_pos = target_brick.m_x_pos + wall.at(next_brick.m_row).at(next_brick.m_col);

                    curr_bricks.emplace( std::move(next_brick) );
                }

            } while( !curr_bricks.empty() && target_x_pos==curr_bricks.top().m_x_pos );

            assert( curr_crossed_num_bricks>=0 && curr_crossed_num_bricks<SIZE );
            if( !curr_bricks.empty() ) // by problem definition
            {
                min_crossed_num_bricks = std::min( min_crossed_num_bricks, curr_crossed_num_bricks );
            }
        }

        return min_crossed_num_bricks;
    }
};
