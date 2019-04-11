class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        // brute force O(n^2)
//         std::unordered_map<VALUE_TYPE, SIZE_TYPE> hash;
//         const auto SIZE_2 = nums2.size();
//         for( SIZE_TYPE i=0; i<SIZE_2; ++i )
//         {
//             if( !hash.count(nums2.at(i)) ) hash[nums2.at(i)] = i;
//         }

//         std::vector<VALUE_TYPE> ans;
//         for( auto curr_num : nums1 )
//         {
//             assert( hash.count(curr_num) );

//             auto next_greater_num = -1;
//             for( auto i=hash[curr_num]+1; i<SIZE_2; ++i )
//             {
//                 if( nums2.at(i) > curr_num )
//                 {
//                     next_greater_num = nums2.at(i);
//                     break;
//                 }
//             }
//             ans.push_back( next_greater_num );
//         }

        // O(n)
        std::vector<VALUE_TYPE> ans;
        std::stack<VALUE_TYPE> left_stack;
        std::unordered_map<VALUE_TYPE, VALUE_TYPE> hash;
        for( auto curr_num : nums2 )
        {
            while( !left_stack.empty() && left_stack.top()<curr_num )
            {
                hash[left_stack.top()] = curr_num;
                left_stack.pop();
            }

            left_stack.push( curr_num );
        }

        for( auto curr_num : nums1 )
        {
            ans.push_back( hash.count(curr_num) ? hash[curr_num] : -1 );
        }

        return ans;
    }
};
