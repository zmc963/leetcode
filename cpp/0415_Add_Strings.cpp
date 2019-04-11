class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    string addStrings( const std::string& num1, const std::string& num2)
    {
        const auto SIZE_1 = num1.size();
        const auto SIZE_2 = num2.size();
        const auto BASE = 10;
        int carry = 0;
        std::string ans;

        for( SIZE_TYPE idx_1=SIZE_1-1, idx_2=SIZE_2-1; idx_1<SIZE_1 || idx_2<SIZE_2; )
        {
            // assert( std::isdigit(num1.at(idx_1)) && std::isdigit(num2.at(idx_2)) );

            auto n1 = idx_1<SIZE_1 ? num1.at(idx_1)-'0' : 0 ;
            auto n2 = idx_2<SIZE_2 ? num2.at(idx_2)-'0' : 0 ;

            auto sum = n1 + n2 + carry;
            ans += std::to_string(sum % BASE);
            carry = sum / BASE;

            if( idx_1 < SIZE_1 ) --idx_1;
            if( idx_2 < SIZE_2 ) --idx_2;
        }

        if( carry > 0 ) ans += std::to_string(carry);

        std::reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
};

