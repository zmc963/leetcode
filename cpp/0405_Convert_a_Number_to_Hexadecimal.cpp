class Solution
{
    using SIZE_TYPE = std::string::size_type;

    std::string ToHex( int num, bool isNegative ) const
    {
        assert( num >= 0 );

        if( !isNegative && num >= 10 ) return std::string(1, num-10+'a');

        return std::string(1, num+'0');
    }

public:
    string toHex(int num)
    {
        std::string ans;
        std::string mapping = "0123456789abcdef";
        auto cnt = sizeof(decltype(num))*2;
        while( num!=0 && cnt-->0 )
        {
            ans = mapping.at(num & 0xf) + ans;
            num >>= 4;
        }

        return ans.empty() ? "0" : ans;

        // slow version
//         if( std::numeric_limits<decltype(num)>::min() == num )
//         {
//             return "8" + std::string(sizeof(decltype(num))*2-1, '0');
//         }
//         else if( 0 == num )
//         {
//             return "0";
//         }

//         bool is_negative = num<0;
//         num = std::abs(num);

//         std::string ans;
//         const auto BASE = 16;
//         for( int exp=0; num!=0; ++exp )
//         {
//             ans = ToHex(num%BASE, is_negative) + ans;
//             num /= BASE;
//         }

//         if( is_negative )
//         {
//             ans = std::string(sizeof(decltype(num))*2-ans.size(), '0') + ans;
//             const auto SIZE = ans.size();
//             int carry = 1;
//             for( SIZE_TYPE i=SIZE-1; i<SIZE; --i )
//             {
//                 auto new_val = BASE-1-(ans.at(i)-'0') + carry;

//                 ans.at(i) = ToHex( new_val%BASE, false ).front();
//                 carry = new_val / BASE;
//             }
//         }

//         return ans;
    }
};
