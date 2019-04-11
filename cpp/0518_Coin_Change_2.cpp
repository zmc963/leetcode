class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int change(int amount, vector<int>& coins)
    {
        std::vector<int> dp( amount+1, 0 );
        dp.front() = 1;

        for( auto coin_denomination : coins )
        {
            for( SIZE_TYPE i=coin_denomination; i<=amount; ++i )
            {
                dp.at(i) += dp.at(i-coin_denomination);
            }
        }

        return dp.back();
    }
};
