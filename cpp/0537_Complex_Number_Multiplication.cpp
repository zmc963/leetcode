class Solution
{
public:
    string complexNumberMultiply(string a, string b)
    {
        std::vector<std::string> input{a, b};
        std::vector<std::pair<int, int>> decoded;
        for( auto&& s : input )
        {
            auto found_plus = s.find_first_of( '+' );
            if( string::npos == found_plus ) return {};

            auto found_i = s.find_first_of( 'i', found_plus+1 );
            if( string::npos == found_i ) return {};

            decoded.emplace_back( std::stoi(s.substr(0, found_plus)), std::stoi(s.substr(found_plus+1, found_i-found_plus-1)) );
        }
        assert( 2 == decoded.size() );

        auto new_a = decoded.at(0).first*decoded.at(1).first - decoded.at(0).second*decoded.at(1).second;
        auto new_b = decoded.at(0).first*decoded.at(1).second + decoded.at(0).second*decoded.at(1).first;

        return std::to_string(new_a) + "+" + std::to_string(new_b) + "i";
    }
};
