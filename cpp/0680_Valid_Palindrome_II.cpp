class Solution
{
    using SIZE_TYPE = std::string::size_type;

    bool ValidPalindromeImp( const std::string& s, int diff_cnt, int diff_cnt_tolerance ) const
    {
        if( s.size() <= 1 ) return true;

        const auto SIZE = s.size();
        SIZE_TYPE left = 0;
        SIZE_TYPE right = SIZE - 1;
        while( right<SIZE && left<right )
        {
            if( s.at(left) == s.at(right) )
            {
                ++left;
                --right;
            }
            else
            {
                ++diff_cnt;
                if( diff_cnt > diff_cnt_tolerance ) break;

                return ValidPalindromeImp( s.substr(left+1, right-left), diff_cnt, diff_cnt_tolerance ) ||
                       ValidPalindromeImp( s.substr(left, right-left), diff_cnt, diff_cnt_tolerance );
            }
        }

        return diff_cnt <= diff_cnt_tolerance;
    }

public:
    bool validPalindrome(string s)
    {
        return ValidPalindromeImp( s, 0, 1 );
    }
};
