class Solution {
public:
    int reverse(int x)
    {
        int reverse_int = 0;
        int ori_x = x;

        while( ori_x != 0 )
        {
            int last_digit = ori_x % 10;

            // this is wrong !!!!!!
            if( (std::numeric_limits<int>::max() / 10 < reverse_int) ||
                (std::numeric_limits<int>::min() / 10 > reverse_int) ||
                (reverse_int > 0 && std::numeric_limits<int>::max() - last_digit < reverse_int*10) ||
                (reverse_int < 0 && std::numeric_limits<int>::min() - last_digit > reverse_int*10) )
            {
                return 0;
            }
            reverse_int *= 10;
            reverse_int += last_digit;
            ori_x /= 10;

            // std::cout << reverse_int << ", " << ori_x << std::endl;
        }

        return reverse_int;
    }
};
