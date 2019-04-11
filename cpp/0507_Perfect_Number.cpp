class Solution {
public:
    bool checkPerfectNumber(int num)
    {
        if( 0 >= num ) return false;

        auto sum = 1;
        for( auto divisor=2; divisor*divisor<=num && sum<=num; ++divisor )
        {
            if( 0 == num % divisor )
            {
                sum += divisor;
                if( num != divisor * divisor )
                {
                    sum += num/divisor;
                }
            }
        }

        return 1!=num && sum==num;
    }
};
