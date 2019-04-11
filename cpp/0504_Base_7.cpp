class Solution {
public:
    string convertToBase7(int num)
    {
        const auto BASE = 7;
        bool is_negative = num < 0;

        std::string ans;
        while( 0 != num )
        {
            ans += std::abs(num % BASE) + '0';
            num /= BASE;
        }

        std::reverse( ans.begin(), ans.end() );
        if( ans.empty() ) ans = "0";

        return is_negative? "-"+ans : ans;
    }
};
