class Solution
{
    // TLE
    void DFS( int m, int n, int remain, int currX, int currY, int modulo, int& cnt ) const
    {
        if( currX>=m || currX<0 || currY>=n || currY<0 )
        {
            ++cnt;
            cnt %= modulo; // by problem definition
            return;
        }
        else if( remain<=0 || (std::min(m-1-currX, currX)>=remain && std::min(n-1-currY, currY)>=remain) )
        {
            return;
        }

        int dirt[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for( auto i=0; i<sizeof(dirt)/sizeof(dirt[0]); ++i )
        {
            DFS( m, n, remain-1, currX+dirt[i][0], currY+dirt[i][1], modulo, cnt );
        }
    }


public:
    int findPaths(int m, int n, int N, int i, int j)
    {
        // m, n, N can be randomly ordered
        std::vector<std::vector<std::vector<int>>> dp( n, std::vector<std::vector<int>>( m, std::vector<int>( N+1, 0 ) ) );

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // N must be in outermost loop, since we calculate DP by accumulated sub DP
        for( auto step=1; step<=N; ++step )
        {
            for( auto row=0; row<m; ++row )
            {
                for( auto col=0; col<n; ++col )
                {
                    for( auto&& d : dirs )
                    {
                        auto new_row = row + d[0];
                        auto new_col = col + d[1];

                        // initial condition
                        if( 0>new_row || new_row>=m || 0>new_col || new_col>=n )
                        {
                            dp.at(col).at(row).at(step) += 1;
                        }
                        else
                        {
                            dp.at(col).at(row).at(step) += dp.at(new_col).at(new_row).at(step-1);
                        }

                        dp.at(col).at(row).at(step) = dp.at(col).at(row).at(step) % 1000000007;
                    }
                }
            }
        }

        return dp.at(j).at(i).at(N);
    }
};
