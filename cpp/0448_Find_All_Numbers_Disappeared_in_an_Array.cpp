class Solution
{
    using SIZE_TYPE = std::vector<std::pair<int, int>>::size_type;

public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        const auto SIZE = nums.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            assert( 1<=std::abs(nums.at(i)) && std::abs(nums.at(i))<=SIZE );
            auto& target_slot = nums.at( std::abs(nums.at(i))-1 );
            if( target_slot > 0 ) target_slot *= -1;
        }

        std::vector<int> ans;
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            if( nums.at(i) > 0 ) ans.push_back(i+1);
        }

        return ans;
    }
};
