class Solution
{
    using SIZE_TYPE = std::string::size_type;
    using VALUE_TYPE = std::string::value_type;

public:
    int minDistance(string word1, string word2)
    {
        const auto SIZE_1 = word1.size();
        const auto SIZE_2 = word2.size();

        std::vector<std::vector<SIZE_TYPE>> dp( SIZE_1+1, std::vector<SIZE_TYPE>( SIZE_2+1, 0 ) );
        for( SIZE_TYPE i=1; i<=SIZE_1; ++i )
        {
            for( SIZE_TYPE j=1; j<=SIZE_2; ++j )
            {
                if( word1.at(i-1) == word2.at(j-1) )
                {
                    dp.at(i).at(j) = dp.at(i-1).at(j-1) + 1;
                }
                else
                {
                    dp.at(i).at(j) = std::max( dp.at(i).at(j-1), dp.at(i-1).at(j) );
                }
            }
        }

        return SIZE_1 + SIZE_2 - dp.back().back()*2;
    }
};

