class Solution
{
    using SIZE_TYPE = std::vector<char>::size_type;
    using VALUE_TYPE = std::vector<char>::value_type;

public:
    int leastInterval(vector<char>& tasks, int n)
    {
        auto max_cnt = std::numeric_limits<SIZE_TYPE>::min();
        auto same_max_cnt = std::numeric_limits<SIZE_TYPE>::min();

        std::unordered_map<VALUE_TYPE, SIZE_TYPE> hash;
        for( auto c : tasks )
        {
            ++hash[c];
            if( max_cnt <= hash[c] )
            {
                if( max_cnt == hash[c] ) ++same_max_cnt;
                else same_max_cnt = 1;

                max_cnt = hash[c];
            }

        }

        auto remainings = tasks.size() - max_cnt * same_max_cnt;
        assert( remainings>=0 && same_max_cnt>=1 );

        if( same_max_cnt >= n+1 )
        {
            return tasks.size();
        }
        else
        {
            auto empty_slots = (n-(same_max_cnt-1))*(max_cnt-1);
            return max_cnt+(max_cnt-1)*n + (same_max_cnt-1) + ((remainings >= empty_slots) ? (remainings-empty_slots) : 0);
        }
    }
};
