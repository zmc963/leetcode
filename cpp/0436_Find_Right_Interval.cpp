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
    vector<int> findRightInterval(vector<Interval>& intervals)
    {
        const auto SIZE = intervals.size();
        std::map<int, SIZE_TYPE> intervals_start;
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            intervals_start.emplace( intervals.at(i).start, i );
        }

        std::vector<int> ans;
        for( auto&& i : intervals )
        {
            auto target_itr = intervals_start.lower_bound( i.end );

            ans.push_back( intervals_start.end()==target_itr ? -1 : target_itr->second );
        }

        return ans;
    }
};
