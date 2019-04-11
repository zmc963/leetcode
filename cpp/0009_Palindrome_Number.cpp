class Solution {
public:
    bool isPalindrome(int x)
    {
        if( x < 0 || (x % 10 == 0 && x != 0) )
        {
            return false;
        }

        auto r_right_half = 0;
        auto curr = x;
        while( curr > r_right_half )
        {
            r_right_half *= 10;
            r_right_half += curr % 10;

            curr /= 10;
        }
        std::cout << curr <<  " " << r_right_half;
        return curr == r_right_half || curr == r_right_half/10;
    }
};
