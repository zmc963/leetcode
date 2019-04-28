class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for( int i=std::sqrt(c); i>=0; --i )
        {
            int d = c - i*i;
            int t = sqrt(d);

            if( t*t == d ) return true;
        }

        return false;
    }
};
