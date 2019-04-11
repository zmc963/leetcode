class Solution
{
    using SIZE_TYPE = std::vector<std::string>::size_type;

public:
    int findMinDifference(vector<string>& timePoints)
    {
        if( timePoints.size() <= 1 ) return -1;
        else if( timePoints.size() > 60*24 ) return 0;

        std::sort( timePoints.begin(), timePoints.end() );

        const auto SIZE = timePoints.size();
        auto pre_minute = -1;
        auto first_minute = -1;
        int min_diff = std::numeric_limits<decltype(min_diff)>::max();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            auto& curr_t = timePoints.at(i);
            auto cur_minute = std::stoi(curr_t.substr(0, 2))*60 + std::stoi(curr_t.substr(3));

            if( 0 == i ) first_minute = cur_minute;
            else if( SIZE-1 == i ) min_diff = std::min( min_diff, 24*60-(cur_minute-first_minute) );

            if( 0 != i ) min_diff = std::min( min_diff, cur_minute-pre_minute );

            pre_minute = cur_minute;
        }

        return min_diff;
    }
};
