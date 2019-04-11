class Solution {
public:
    int arrangeCoins(int n)
    {
        long long left = 0;
        long long right = (n/2) + 1;

        while( left <= right )
        {
            auto mid = left + (right-left) / 2;
            auto diff = (mid * (mid+1))/2 - n;

            if( diff > 0 ) right = mid - 1;
            else if( diff < 0 ) left = mid + 1;
            else return mid;
        }

        return left-1;
    }
};


