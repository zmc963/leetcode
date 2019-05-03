class Solution
{
    using IDX_TYPE = std::string::size_type;

public:
    bool isPalindrome(string s)
    {
        if( s.size() <= 1 ) return true;

        const auto SIZE = s.size();
        IDX_TYPE left = 0;
        IDX_TYPE right = SIZE-1;

        while( right<SIZE && left<right )
        {
            while( (left<right) && !std::isalnum(s.at(left)) ) ++left;
            while( (right>left) && !std::isalnum(s.at(right)) ) --right;

            if( std::tolower(s.at(left)) != std::tolower(s.at(right)) )
            {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};
