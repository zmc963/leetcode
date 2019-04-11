class Solution {
public:
    string countAndSay(int n)
    {
        assert( n >= 1 );

        std::string s("1");
        for( auto i=2; i<=n; ++i )
        {
            const auto SIZE = s.size();
            std::string::size_type left = 0;
            std::string::size_type right = left;
            std::string curr_s;

            while( right < SIZE )
            {
                auto target = s.at(left);
                while( right<SIZE && s.at(right)==target )
                {
                    right++;
                }
                assert( right > left );
                curr_s += std::to_string(right-left) + target;
                left = right;
            }
            s = curr_s;
        }

        return s;
    }
};
