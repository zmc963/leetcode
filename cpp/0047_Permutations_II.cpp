class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        std::unordered_map<int, int> hash;
        for( auto i : nums ) ++hash[i];

        std::vector<int> new_nums;
        for( auto i : hash ) new_nums.push_back( i.first );

        vector<vector<int>> ans;
        std::vector<int> curr_perm;
        PermImp( new_nums, hash, nums.size(), curr_perm, ans );

        return ans;
    }

private:
    void PermImp(
        const std::vector<int>& nums,
        std::unordered_map<int, int> numsHash,
        std::vector<int>::size_type maxPermSize,
        std::vector<int>& currPerm,
        std::vector<std::vector<int>>& ans ) const
    {
        assert( currPerm.size() <= maxPermSize );
        assert( nums.size() <= maxPermSize );

        if( maxPermSize == currPerm.size() )
        {
            ans.push_back( currPerm );
            return;
        }

        for( auto n : nums )
        {
            auto& bucket = numsHash[n];
            if( 0 != bucket )
            {
                --bucket;

                currPerm.push_back(n);
                PermImp( nums, numsHash, maxPermSize, currPerm, ans );
                currPerm.pop_back();

                ++bucket;
            }
        }
    }
};
