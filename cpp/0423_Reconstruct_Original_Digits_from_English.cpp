class Solution
{
    using SIZE_TYPE = std::string::size_type;
    using VALUE_TYPE = std::string::value_type;

    bool ComputeValidCombination( const std::vector<int>& hash, const std::vector<int>& num, std::vector<int>& output )
    {
        assert( hash.size() == num.size() );

        output = hash;
        const auto SIZE = hash.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            if( output.at(i) < num.at(i) )
            {
                return false;
            }

            output.at(i) -= num.at(i);
        }

        return true;
    }

public:
    string originalDigits(string s)
    {
        const auto NUM_SIZE = 10;
        std::vector<int> hash(26, 0);
        for( auto c : s ) ++hash[c-'a'];

        std::vector<std::vector<int>> num( NUM_SIZE, std::vector<int>(26, 0) );
        std::vector<std::pair<std::string, int>> num_str // the order matters
        {
            {"zero", 0}, {"two", 2}, {"four", 4}, {"six", 6}, {"eight", 8}, {"one", 1}, {"three", 3}, {"five", 5}, {"seven", 7}, {"nine", 9} };

        assert( num.size()==num_str.size() && num.size()==NUM_SIZE );
        for( auto i=0; i<NUM_SIZE; ++i )
        {
            for( auto c : num_str.at(i).first ) ++num.at(i).at(c-'a');
        }

        std::string ans;
        for( auto i=0; i<NUM_SIZE; ++i )
        {
            std::vector<int> output;
            while( ComputeValidCombination( hash, num.at(i), output ) )
            {
                ans += std::to_string(num_str.at(i).second);
                hash = output;
            }
        }

        std::sort( ans.begin(), ans.end() );
        return ans;
    }
};
