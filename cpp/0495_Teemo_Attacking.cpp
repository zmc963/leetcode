class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        // std::sort( timeSeries.begin(), timeSeries.end() ); // already sorted by problem definition

        VALUE_TYPE end = 0;
        int time_duration = 0;
        for( auto curr_time : timeSeries )
        {
            time_duration += duration;
            if( curr_time <= end )
            {
                time_duration -= end - curr_time;
            }

            end = std::max( curr_time+duration, end );
        }

        return time_duration;
    }
};
