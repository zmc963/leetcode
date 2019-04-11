class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    int maxRotateFunction(vector<int>& A)
    {
        // sum = 1A + 1B + 1C + 1D...
        // F(0) = 0A + 1B + 2C +3D...
        // F(i) = F(i-1) + sum - n*A[n-i]

        long long f0 = 0;
        long long sum = 0;
        const auto SIZE = A.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            sum += A.at(i);
            f0 += i * A.at(i);
        }

        long long max_sum = f0;
        long long f = f0;
        for( SIZE_TYPE n=1; n<SIZE; ++n )
        {
            f += sum - SIZE*A.at(SIZE-n);
            max_sum = std::max( max_sum, f );
        }

        return max_sum;
    }
};
