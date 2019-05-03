class Solution {
public:
    bool hasAlternatingBits(int n)
    {
//         constexpr auto BASE = 2;
//         auto prev_bit = 0;
//         auto temp_n = n;
//         while( 0 != temp_n )
//         {
//             auto curr_bit = temp_n % BASE;
//             if( n!=temp_n && curr_bit==prev_bit ) return false;

//             temp_n /= BASE;

//             prev_bit = curr_bit;
//         }

        std::make_unsigned<decltype(n)>::type un = n;

        auto d = un & 1;
        while( (un & 1) == d )
        {
            d ^= 1;
            un >>= 1;
        }

        return un == 0;
    }
};
