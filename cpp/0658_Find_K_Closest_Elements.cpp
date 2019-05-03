class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    vector<int> findClosestElements( std::vector<int>& arr, int k, int x )
    {
        const auto SIZE = arr.size();
        // if( arr.size() <= k ) return arr;

        auto itr = std::lower_bound( arr.begin(), arr.end(), x );
        // adjust to nearest valid one
        // if( arr.end()==itr || (*itr!=x && itr!=arr.begin() && x-*(itr-1)<=(*itr-x)) ) --itr;
        // assert( arr.end() != itr );

        SIZE_TYPE left = itr-arr.begin();
        SIZE_TYPE right = left;

        left = left>=k ? left-k : 0;
        right = SIZE-1-right>=k ? right+k : SIZE-1;
        assert( left>=0 && right<=SIZE-1 && left<=right );

        std::vector<int> ans;
        while( right-left+1 > k )
        {
            auto diff = x-arr.at(left) - (arr.at(right)-x);
            if( 0 < diff ) ++left;
            else --right;
        }

        return std::vector( arr.begin()+left, arr.begin()+right+1 );
    }
};
