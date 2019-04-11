class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    void FindSubsequencesImp(
        const std::vector<int>& nums,
        SIZE_TYPE start,
        std::vector<int>& curr,
        std::vector<std::vector<int>>& ans ) const
    {
        assert( start <= nums.size() );

        if( curr.size() >= 2 ) ans.push_back( curr );

        std::unordered_set<int> used;
        const auto SIZE = nums.size();
        for( SIZE_TYPE i=start; i<SIZE; ++i )
        {
            auto curr_num = nums.at(i);
            if( (curr.empty() || curr_num>=curr.back()) && !used.count(curr_num) )
            {
                curr.push_back( curr_num );
                FindSubsequencesImp( nums, i+1, curr, ans );
                curr.pop_back();
            }
            used.insert( curr_num );
        }
    }

public:
    std::vector<std::vector<int>> findSubsequences(vector<int>& nums)
    {
        if( nums.empty() ) return {};

        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        FindSubsequencesImp( nums, 0, curr, ans );

        return ans;
    }
};
