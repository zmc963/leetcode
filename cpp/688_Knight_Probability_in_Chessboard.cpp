class Solution
{
    // must use double by problem's input scope
    using VALUE_TYPE = double;

public:
    double knightProbability(int N, int K, int r, int c)
    {
        if( r<0 || c<0 || r>=N || c>=N ) return {};

        std::vector<std::vector<VALUE_TYPE>> dp_inside( N, std::vector<VALUE_TYPE>(N, 1) );

        VALUE_TYPE dirs[8][2] = {{2,1}, {2,-1}, {1,2}, {1,-2}, {-2,1}, {-2,-1}, {-1,2}, {-1,-2}};
        const auto SIZE_DIRECTIONS = sizeof(dirs) / sizeof(dirs[0]);

        for( auto step=1; step<=K; ++step )
        {
            std::vector<std::vector<VALUE_TYPE>> dp_new( N, std::vector<VALUE_TYPE>(N, 0) );
            for( auto row=0; row<N; ++row )
            {
                for( auto col=0; col<N; ++col )
                {
                    for( auto&& d : dirs )
                    {
                        auto new_row = row + d[0];
                        auto new_col = col + d[1];

                        if( 0>new_row || new_row>=N || 0>new_col || new_col>=N ) continue;

			dp_new.at(row).at(col) += dp_inside.at(new_row).at(new_col);
                    }
                }
            }
            dp_inside.swap( dp_new );
        }

        return dp_inside.at(r).at(c) / std::pow(SIZE_DIRECTIONS, K);
    }
};
