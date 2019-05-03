class Solution
{
    using STATE_TYPE = unsigned;
    using SIZE_TYPE = std::vector<int>::size_type;

    // O(k^n) -> O(k^(n-k)*k!) optimized brute force
//     bool BruteForceSearch( const std::vector<int>& nums, SIZE_TYPE currIdx, int target, std::vector<int>& buckets ) const
//     {
//         assert( currIdx <= nums.size() );

//         // don't need to check buckets' vals here if we do our pruning job well
//         if( currIdx == nums.size() ) return true;

//         auto curr_num = nums.at(currIdx);
//         if( curr_num > target ) return false;

//         const auto SIZE = buckets.size();
//         for( SIZE_TYPE i=0; i<SIZE; ++i )
//         {
//             auto& b = buckets.at(i);

//             if( (i==0 || buckets.at(i-1)!=b) && b+curr_num<=target )
//             {
//                 b += curr_num;
//                 if( BruteForceSearch( nums, currIdx+1, target, buckets ) ) return true;
//                 b -= curr_num;
//             }

//             if( b == 0 ) break;
//         }

//         return false;
//     }

    // O(n*2^n)
    bool BruteForceSearch(
        const std::vector<int>& nums,
        STATE_TYPE used,
        int todo,
        int target,
        std::unordered_set<STATE_TYPE>& visit ) const
    {
        if( 0 == todo ) return true;

        if( !visit.count(used) )
        {
            visit.insert(used);

            // we want 1 ~ target here
            auto remain = (todo - 1) % target + 1;
            const auto SIZE = nums.size();

            for( SIZE_TYPE i=0; i<SIZE; ++i )
            {
                auto curr_num = nums.at(i);

                if( (((used >> i) & 1) == 0) && curr_num<=remain )
                {
                    if( BruteForceSearch( nums, used | (1<<i), todo-curr_num, target, visit ) ) return true;
                }
            }
        }

        return false;
    }

public:
    bool canPartitionKSubsets( std::vector<int>& nums, int k )
    {
        if( nums.size()>(sizeof(STATE_TYPE)*CHAR_BIT) || k<1 || k>nums.size() ) return false;
        if( 1 == k ) return true;

        auto sum = std::accumulate( nums.begin(), nums.end(), 0 );
        if( 0 != sum % k ) return false;

        // std::sort( nums.rbegin(), nums.rend() );
        // std::vector<int> buckets(k);
        // return BruteForceSearch( nums, 0, sum/k, buckets );

        std::unordered_set<STATE_TYPE> visit;
        return BruteForceSearch( nums, 0, sum, sum/k, visit );

        // O(n2^n) if search in record takes O(1), but apparently it's not here
//         sum /= k;
//         const auto SIZE = nums.size();
//         const STATE_TYPE MAX_VAL = std::pow( 2, SIZE );
//         std::unordered_map<int, int> record;

//         for( STATE_TYPE state=1; state<=MAX_VAL; ++state )
//         {
//             auto curr_sum = 0;
//             for( auto i=0; i<SIZE && curr_sum<=sum; ++i )
//             {
//                 if( state & (0x01<<i) ) curr_sum += nums.at(i);
//             }

//             if( sum == curr_sum )
//             {
//                if( record.size() >= 100 ) std::cout << record.size() << " ";
//                 auto temp_record = record;
//                 for( auto&& r : record )
//                 {
//                     if( 0 == (state & r.first) )
//                     {
//                         auto combined = state | r.first;
//                         auto another_part = MAX_VAL ^ combined;

//                         if( k==r.second+1 ||
//                             (record.count(another_part) && k==r.second+1+record[another_part]) ) return true;

//                         temp_record[combined] = r.second+1;
//                     }
//                 }

//                 assert( !record.count(state) );
//                 temp_record[state] = 1;

//                 record.swap(temp_record);
//             }
//         }

//         return false;
    }
};
