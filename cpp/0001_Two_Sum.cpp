#include <unordered_multimap>

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target)
    {
        std::unordered_map<int, int> hash;
        const auto SIZE = nums.size();

        for( std::vector<int>::size_type i=0; i<SIZE; ++i )
        {
            int offset = target - nums.at(i);

            auto itr = hash.find(offset);
            if( hash.end() != itr )
            {
                assert( i != itr->second );
                return {i, itr->second};
            }

            hash.insert( {nums.at(i), i} );
        }

        assert(1);
        return {};
    }
};
