class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int findDuplicate(vector<int>& nums)
    {
        const auto SIZE = nums.size();

        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            auto curr_num = std::abs(nums.at(i));
            assert( 1<=curr_num && curr_num<SIZE );

            // swap
            while( nums.at(i) != nums.at(nums.at(i)-1) )
            {
                std::swap( nums.at(i), nums.at(nums.at(i)-1) );
            }

            if( nums.at(i) != i+1 ) return nums.at(i);

            // negative number
//             if( nums.at(curr_num) < 0 )
//             {
//                 return curr_num;
//             }

//             nums.at(curr_num) = -nums.at(curr_num);
        }

        return -1;

//         int slow = 0, fast = 0, t = 0;
//         while (true) {
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//             if (slow == fast) break;
//         }

//         std::cout << slow << ", " << fast << std::endl;
//         while (true) {
//             slow = nums[slow];
//             t = nums[t];
//             if (slow == t) break;
//         }
//         return slow;
    }
};
