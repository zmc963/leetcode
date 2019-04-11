class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        std::stack<std::pair<VALUE_TYPE, SIZE_TYPE>> left_stack;
        std::unordered_set<SIZE_TYPE> calculated;
        const auto SIZE = nums.size();
        std::vector<int> ans( SIZE, -1 );

//         for( SIZE_TYPE i=0; i<SIZE; ++i )
//         {
//             auto curr_num = nums.at(i);
//             while( !left_stack.empty() && left_stack.top().first<curr_num )
//             {
//                 ans.at(left_stack.top().second) = curr_num;
//                 calculated.insert(left_stack.top().second);
//                 left_stack.pop();
//             }

//             left_stack.emplace( curr_num, i );
//         }

//         for( SIZE_TYPE left=0, right=SIZE-1; left<right && right<SIZE; --right )
//         {
//             if( calculated.count(right) ) continue;

//             auto curr_num = nums.at(right);
//             while( left<right && nums.at(left)<=curr_num ) ++left;

//             if( nums.at(left) > curr_num ) ans.at(right) = nums.at(left);
//         }

//         return ans;

        for( SIZE_TYPE i=0; i<2*SIZE; ++i )
        {
            auto curr_num = nums.at(i%SIZE);
            while( !left_stack.empty() && left_stack.top().first<curr_num )
            {
                ans.at(left_stack.top().second) = curr_num;
                left_stack.pop();
            }

            if( i < SIZE ) left_stack.emplace( curr_num, i );
        }

        return ans;
    }
};
