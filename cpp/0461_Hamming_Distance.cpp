class Solution {
public:
    int hammingDistance(int x, int y)
    {
        auto res = x^y;

        int count = 0;
        for( auto i=0; i<sizeof(decltype(x))*CHAR_BIT; ++i )
        {
            count += (res & (0x01<<i)) >> i;
        }

        return count;
    }
};
