class Solution
{
    long long IntegerReplacementImp( long long n, int target ) const
    {
        if( n == target )
        {
            return 0;
        }

        if( 0 == n % 2 )
        {
            return IntegerReplacementImp( n/2, target ) + 1;
        }
        else
        {
            return std::min(
                IntegerReplacementImp( (n+1)/2, target ),
                IntegerReplacementImp( (n-1)/2, target ) ) + 2;
        }
    }

public:
    int integerReplacement(int n)
    {
        return IntegerReplacementImp( n, 1 );
    }
};
