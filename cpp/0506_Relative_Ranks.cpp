class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

public:
    vector<string> findRelativeRanks( vector<int>& nums )
    {
        std::vector<std::pair<VALUE_TYPE, SIZE_TYPE>> temp;

        const auto SIZE = nums.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i ) temp.emplace_back( nums.at(i), i );

        std::sort( temp.begin(), temp.end(), std::greater<std::pair<VALUE_TYPE, SIZE_TYPE>>() );

        std::vector<std::string> ans( SIZE );
        auto rank = 1;
        for( auto&& t : temp )
        {
            if( 1 == rank ) ans.at(t.second) = "Gold Medal";
            else if( 2 == rank ) ans.at(t.second) = "Silver Medal";
            else if( 3 == rank ) ans.at(t.second) = "Bronze Medal";
            else ans.at(t.second) = std::to_string(rank);

            ++rank;
        }

        return ans;
    }
};
