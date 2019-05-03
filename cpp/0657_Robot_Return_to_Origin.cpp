class Solution
{
public:
    bool judgeCircle(string moves)
    {
        std::pair<long long, long long> pos;
        for( auto c : moves )
        {
            if( 'R' == c ) pos.first += 1;
            else if( 'U' == c ) pos.second += -1;
            else if( 'D' == c ) pos.second += 1;
            else if( 'L' == c ) pos.first += -1;
        }

        return pos.first==0 && pos.second==0;
    }
};
