class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        if( k < 1 ) return 0.0;

        double sum = std::accumulate( nums.begin(), nums.begin()+k, 0 );
        auto max_avg = sum;

        const auto SIZE = nums.size();
        for( SIZE_TYPE i=k; i<SIZE; ++i )
        {
            sum += nums.at(i)-nums.at(i-k);
            max_avg = std::max( max_avg, sum );
        }

        return max_avg / k;
    }
};
