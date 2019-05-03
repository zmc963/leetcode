class Solution
{
    void MinStepsImp( int n, int currN, int currCopied, int currStep, int& minStep ) const
    {
        if( n<=currN )
        {
            if( n == currN ) minStep = std::min( minStep, currStep );
            return;
        }

        // paste
        if( 0!= currCopied ) MinStepsImp( n, currN+currCopied, currCopied, currStep+1, minStep );

        // copy
        if( currN != currCopied ) MinStepsImp( n, currN, currN, currStep+1, minStep );
    }

public:
    int minSteps(int n)
    {
        // raw brute force
        // auto min_step = std::numeric_limits<int>::max();
        // MinStepsImp( n, 1, 0, 0, min_step );
        // return min_step;

        std::vector<int> dp(n+1);

        for( auto i=2; i<=n; ++i )
        {
            dp.at(i) = std::numeric_limits<int>::max();
            for( auto j=i-1; j>=1; --j )
            {
                if( 0 == i%j )
                {
                    dp.at(i) = std::min( dp.at(i), dp.at(j)+i/j );
                }

            }
        }

        return dp.back();
    }
};
