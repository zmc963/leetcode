class Solution
{
    using IDX_TYPE = std::vector<int>::size_type;

    void Reverse( vector<int>& nums, IDX_TYPE left, IDX_TYPE right )
    {
        auto mid = (right-left) / 2;
        std::cout << left << " " << right << " " << mid << std::endl;
        for( IDX_TYPE i=0; i<=mid; ++i )
        {
            std::swap( nums.at(left+i), nums.at(right-i) );
        }
    }

public:
    void nextPermutation(vector<int>& nums)
    {
        if( nums.size() <= 1 )
        {
            return;
        }

        const auto SIZE = nums.size();
        IDX_TYPE i = SIZE - 2;
        while( (i<SIZE) && (nums.at(i+1) <= nums.at(i)) )
        {
            --i;
        }

        if( i != std::numeric_limits<decltype(i)>::max() )
        {
            auto target = nums.at(i);
            IDX_TYPE j = nums.size() - 1;
            while ( (j<SIZE) && (nums.at(j) <= target) )
            {
                --j;
            }

            std::swap( nums.at(i), nums.at(j) );
        }

        Reverse( nums, i+1, SIZE-1 );

//         const auto SIZE = nums.size();
//         for( IDX_TYPE i=SIZE-1; i>=1; --i )
//         {
//             if( nums.at(i-1) < nums.at(i) )
//             {
//                 auto target = nums.at(i-1);
//                 IDX_TYPE j = i+1;
//                 for( ; j<SIZE; ++j )
//                 {
//                     if( nums.at(j) <= target )
//                     {
//                         break;
//                     }
//                 }

//                 std::swap( nums.at(i-1), nums.at(j-1) );
//                 Reverse( nums, i, SIZE-1 );
//                 return;
//             }
//         }

//         Reverse( nums, 0, SIZE-1 );
    }
};
