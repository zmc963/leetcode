class Solution {
public:
    string intToRoman(int num)
    {
        // 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000
        using ROMAN_NUM_TYPE = std::vector<std::pair<int, std::string>>;
        using ROMAN_NUM_IDX_TYPE = ROMAN_NUM_TYPE::size_type;
        ROMAN_NUM_TYPE nums
        { {1000, "M"},
          {900, "CM"},
          {500, "D"},
          {400, "CD"},
          {100, "C"},
          {90, "XC"},
          {50, "L"},
          {40, "XL"},
          {10, "X"},
          {9, "IX"},
          {5, "V"},
          {4, "IV"},
          {1, "I"}, };

        std::string ans;
        auto curr = num;
        ROMAN_NUM_IDX_TYPE idx = 0;
        const auto SIZE = nums.size();
        while( 0 != curr )
        {
            for( ; SIZE>idx; )
            {
                if( nums.at(idx).first <= curr )
                {
                    curr -= nums.at(idx).first;
                    ans += nums.at(idx).second;
                    break;
                }
                else
                {
                    ++idx;
                }
            }
        }

        return ans;
    }
};
