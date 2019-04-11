class Solution {
public:
    vector<vector<int>> permute( vector<int>& nums )
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> remaining_num;
        remaining_num.resize( nums.size(), NOT_CHOSEN );
        std::vector<int> curr_perm;

        PermImp( nums, nums.size(), remaining_num, curr_perm, ans );

        return ans;
    }

private:
    void PermImp(
        const vector<int>& nums,
        const std::vector<int>::size_type OUTPUT_NUM_INTS,
        vector<int>& remainingNums,
        std::vector<int>& currPerm,
        std::vector<std::vector<int>>& ans ) const
    {
        assert( remainingNums.size() == nums.size() );

        if( OUTPUT_NUM_INTS == currPerm.size() )
        {
            ans.push_back( currPerm );
            return;
        }

        const auto SIZE = remainingNums.size();
        for( auto i=0; i<SIZE; ++i )
        {
            if( NOT_CHOSEN == remainingNums.at(i) )
            {
                remainingNums.at(i) = CHOSEN;

                currPerm.push_back( nums.at(i) );
                PermImp( nums, OUTPUT_NUM_INTS, remainingNums, currPerm, ans );
                currPerm.pop_back();

                remainingNums.at(i) = NOT_CHOSEN;
            }
        }
    }

    static constexpr int CHOSEN = 1;
    static constexpr int NOT_CHOSEN = 0;
};
