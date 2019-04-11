class Solution {
public:
    int fib(int N)
    {
        if( 0 > N ) return -1;
        else if( 1 >= N ) return 0;

        auto fn = 0;
        for( auto i=2, fn_2=0, fn_1=1; i<=N; ++i )
        {
            fn = fn_2 + fn_1;

            fn_2 = fn_1;
            fn_1 = fn;
        }

        return fn;
    }
};
