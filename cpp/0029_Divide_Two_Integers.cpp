class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if( dividend == INT_MIN && divisor == -1 )
        {
            return INT_MAX;
        }

        bool is_negative_dividend = dividend>0;
        bool is_negative_divisor = divisor>0;

        long dividend_l = dividend;
        long divisor_l = divisor;

        dividend_l = std::labs(dividend_l);
        divisor_l = std::labs(divisor_l);

        long quotient = 0;
        while( divisor_l <= dividend_l )
        {
            auto t_divisor = divisor_l;
            long t_q = 1;
            while( (t_divisor<<1) <= dividend_l )
            {
                t_divisor <<= 1;
                t_q <<= 1;
            }

            dividend_l -= t_divisor;
            quotient += t_q;
        }

        return quotient * (is_negative_dividend^is_negative_divisor ? -1 : 1);
    }
};
