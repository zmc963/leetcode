class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    static constexpr auto PLANTED = 1;

public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        const auto SIZE = flowerbed.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            if( PLANTED != flowerbed.at(i) )
            {
                if( (i+1==SIZE || PLANTED!=flowerbed.at(i+1)) &&
                    (i==0 || PLANTED!=flowerbed.at(i-1)) )
                {
                    flowerbed.at(i) = PLANTED;
                    --n;
                    if( n <= 0 ) break;

                    ++i;
                }
            }
        }

        return n<=0;
    }
};
