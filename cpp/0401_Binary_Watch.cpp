class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    bool IsValidTime( int time, int maxTime ) const
    {
        return time>=0 && time<=maxTime;
    }

    void Combination(
        const std::vector<int>& nums,
        SIZE_TYPE start,
        int chosenMaxCnt,
        int currChosenCnt,
        int currAns,
        std::vector<int>& ans ) const
    {
        assert( currChosenCnt <= chosenMaxCnt );
        assert( chosenMaxCnt <= nums.size() );
        assert( start <= nums.size() );

        if( start==nums.size() || currChosenCnt==chosenMaxCnt )
        {
            if( currChosenCnt == chosenMaxCnt ) ans.push_back( currAns );
            return;
        }

        const auto SIZE = nums.size();
        for( SIZE_TYPE i=start; i<SIZE; ++i )
        {
            Combination( nums, i+1, chosenMaxCnt, currChosenCnt+1, currAns+nums.at(i), ans );
        }
    }

public:
    std::vector<std::string> readBinaryWatch(int num)
    {
        const auto LEFT_LED_COUNT = 4;
        const auto RIGHT_LED_COUNT = 6;

        if( num>LEFT_LED_COUNT+RIGHT_LED_COUNT || num<0 ) return {};

        std::vector<int> hour{8, 4, 2, 1};
        std::vector<int> minute{32, 16, 8, 4, 2, 1};
        std::vector<std::string> ans;

        for( auto i=0; i<=num; ++i )
        {
            auto left_LED_on_max_count = std::min(LEFT_LED_COUNT, i);
            auto right_LED_on_max_count = num - left_LED_on_max_count;

            if( right_LED_on_max_count > RIGHT_LED_COUNT ) continue;

            std::vector<int> left;
            Combination( hour, 0, left_LED_on_max_count, 0, 0, left );

            std::vector<int> right;
            Combination( minute, 0, right_LED_on_max_count, 0, 0, right );

            for( auto left_part : left )
            {
                if( !IsValidTime(left_part, 11) ) continue;

                for( auto right_part : right )
                {
                    if( IsValidTime(right_part, 59) )
                    {
                        ans.push_back( std::to_string(left_part) + ":" + ((right_part<=9?"0":"") + std::to_string(right_part)) );
                    }
                }
            }
        }

        return ans;
    }
};

