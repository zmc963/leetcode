class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

public:
    int thirdMax(vector<int>& nums)
    {
        if( nums.empty() ) return -1;

        const auto MIN_VAL = std::numeric_limits<long long>::min();
        auto max_val = MIN_VAL;
        auto second_max_val = MIN_VAL;
        auto third_max_val = MIN_VAL;

        for( auto curr_num : nums )
        {
            if( curr_num > max_val )
            {
                third_max_val = second_max_val;
                second_max_val = max_val;
                max_val = curr_num;
            }
            else if( curr_num<max_val && curr_num>second_max_val )
            {
                third_max_val = second_max_val;
                second_max_val = curr_num;
            }
            else if( curr_num<second_max_val && curr_num>third_max_val )
            {
                third_max_val = curr_num;
            }
        }

        return third_max_val!=MIN_VAL ? third_max_val : max_val;
    }

//     int thirdMax(vector<int>& nums)
//     {
//         if( nums.empty() ) return -1;

//         VALUE_TYPE max_val = 0;
//         bool is_max_inited = false;

//         VALUE_TYPE second_max_val = 0;
//         bool is_second_max_inited = false;

//         VALUE_TYPE third_max_val = 0;
//         bool is_third_max_inited = false;

//         for( auto curr_num : nums )
//         {
//             if( !is_max_inited || (curr_num > max_val) )
//             {
//                 third_max_val = second_max_val;
//                 second_max_val = max_val;
//                 max_val = curr_num;

//                 is_third_max_inited = is_second_max_inited;
//                 is_second_max_inited = is_max_inited;
//                 is_max_inited = true;
//             }
//             else if( curr_num<max_val && (!is_second_max_inited || curr_num>second_max_val) )
//             {
//                 third_max_val = second_max_val;
//                 second_max_val = curr_num;

//                 is_third_max_inited = is_second_max_inited;
//                 is_second_max_inited = true;
//             }
//             else if( curr_num<second_max_val && (!is_third_max_inited || curr_num>third_max_val) )
//             {
//                 is_third_max_inited = true;
//                 third_max_val = curr_num;
//             }

//         }

//         return is_third_max_inited ? third_max_val : max_val;
//     }

};
