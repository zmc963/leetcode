class Solution
{
    int GCD( int left, int right ) const
    {
        return left==0 ? right : GCD( right%left, left );
    }

public:
    string fractionAddition(string expression)
    {
        std::istringstream is(expression);
        int numerator = 0;
        int denominator = 0;
        std::string::value_type division = '/';

        int res_numerator = 0;
        int res_denominator = 1;

        while( is >> numerator >> division >> denominator )
        {
            if( is.fail() ) return {};

            res_numerator = res_numerator*denominator + res_denominator*numerator;
            res_denominator *= denominator;

            auto g = GCD( std::abs(res_numerator), std::abs(res_denominator) );

            res_numerator /= g;
            res_denominator /= g;
        }

        return std::to_string(res_numerator) + '/' + std::to_string(res_denominator);
    }
};
