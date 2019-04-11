/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
    using SIZE_TYPE = std::vector<Interval>::size_type;

public:
    int eraseOverlapIntervals(vector<Interval>& intervals)
    {
        if( intervals.empty() ) return 0;

        std:sort( intervals.begin(), intervals.end(), []( const auto& left, const auto& right )
            {
                return left.end==right.end ? left.start<right.start : left.end<right.end;
            });

        SIZE_TYPE count = 0;
        const auto SIZE = intervals.size();
        int end = intervals.front().end;
        for( SIZE_TYPE i=1; i<SIZE; ++i )
        {
            if( intervals.at(i).start < end )
            {
                ++count;
            }
            else
            {
                end = intervals.at(i).end;
            }
        }

        return count;
    }
};
