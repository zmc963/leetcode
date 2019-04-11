class Solution {
public:
    string multiply(string num1, string num2)
    {
        using IDX_TYPE = std::string::size_type;

        std::string ans;
        const auto NUM1_SIZE = num1.size();
        const auto NUM2_SIZE = num2.size();
        const auto ANS_SIZE = NUM1_SIZE+NUM2_SIZE;
        ans.resize( ANS_SIZE, '0' );

        for( IDX_TYPE i=NUM1_SIZE-1, gap=0; i<NUM1_SIZE; --i, ++gap )
        {
            int carry = 0;
            int multiplicand = num1.at(i) - '0';
            for( IDX_TYPE j=NUM2_SIZE-1; j<NUM2_SIZE; --j )
            {
                int multiplier = num2.at(j) - '0';

                auto cur_res_idx = gap + NUM2_SIZE-1-j;
                int res = (ans.at(cur_res_idx)-'0') + multiplicand*multiplier + carry;
                ans.at(cur_res_idx) = (res % 10) + '0';
                carry = res / 10;

                // std::cout << ans << " " << res << " " << ans.at(cur_res_idx) << " " << carry << std::endl;
            }

            assert( ans.at(gap+NUM2_SIZE) >= '0' && ans.at(gap+NUM2_SIZE) <= '9' );
            ans.at(gap+NUM2_SIZE) += carry;
        }

        IDX_TYPE i = ANS_SIZE-1;
        while( (i<ANS_SIZE) && ('0'==ans.at(i)) ) --i;

        if( i < ANS_SIZE )
        {
            ans = ans.substr(0, i+1);
            std::reverse(ans.begin(), ans.end());
        }
        else
        {
            ans = "0";
        }

        return ans;
    }
};
