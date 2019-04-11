class Solution {
public:
    int romanToInt(string s)
    {
        std::unordered_map<std::string, int> roman_hash =
        { {"I", 1},
          {"IV", 4},
          {"V", 5},
          {"IX", 9},
          {"X", 10},
          {"XL", 40},
          {"L", 50},
          {"XC", 90},
          {"C", 100},
          {"CD", 400},
          {"D", 500},
          {"CM", 900},
          {"M", 1000},};

        int num = 0;
        const auto SIZE = s.size();
        for( std::string::size_type i=0; i<SIZE; ++i )
        {
            auto itr = roman_hash.find( std::string(s, i, 2) );
            if( roman_hash.end() != itr )
            {
                num += itr->second;
                ++i;
                continue;
            }

            itr = roman_hash.find( std::string(s, i, 1) );
            if( roman_hash.end() != itr )
            {
                num += itr->second;
            }
            else
            {
                assert(false);
            }
        }

        return num;
    }
};
