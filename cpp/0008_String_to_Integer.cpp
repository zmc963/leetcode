class Solution {
public:
    int myAtoi(string str)
    {
        int num = 0;
        bool is_negative = false;
        enum State{ T0, T1, T2 };

        State curr_state = T0;
        for( auto c : str )
        {
            if( std::isdigit(c) )
            {
                if( num > 0 && is_negative )
                {
                    num = -num;
                }
                curr_state = T2;
                // overflow
                // '0' is not good
                int last_digit = (c - '0');
                last_digit = is_negative ? -last_digit : last_digit;
                if( !is_negative &&
                    (((std::numeric_limits<int>::max() / 10) < num) ||
                     ((std::numeric_limits<int>::max() - last_digit) < 10*num)) )
                {
                    return std::numeric_limits<int>::max();
                }
                else if( is_negative &&
                    (((std::numeric_limits<int>::min() / 10) > num) ||
                    ((std::numeric_limits<int>::min() - last_digit) > 10*num)) )
                {
                    return std::numeric_limits<int>::min();
                }

                num = num*10 + last_digit;
            }
            else if( '+' == c || '-' == c )
            {
                if( T0 != curr_state )
                {
                    break;
                }

                curr_state = T1;
                if( '-' == c )
                {
                    is_negative = true;
                }
            }
            else if( ' ' == c )
            {
                if( T0 != curr_state )
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }

        return num;
    }
};
