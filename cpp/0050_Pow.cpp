class Solution {
public:
    double myPow(double x, int n)
    {
        if( 1.0 == x ) return 1;

        bool is_negative = (0>n) ? true : false;
        long long new_n = n;
        new_n = is_negative ? -new_n : new_n;
        static_assert( sizeof(long long) > sizeof(int), "" );

        double ans = 1.0;
        while( 0 != new_n )
        {
            if( 1 == new_n % 2 )
            {
                ans *= x;
            }

            new_n /= 2;
            x = x*x;
        }

        return is_negative ? 1.0/ans : ans;
    }
};
