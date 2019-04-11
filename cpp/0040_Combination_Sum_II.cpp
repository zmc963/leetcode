class Solution
{
    using IDX_TYPE = std::vector<int>::size_type;
    void BackTracking(
        const std::vector<int>& candidates,
        int target,
        int currSum,
        IDX_TYPE currCanIdx,
        std::vector<int>& currCombination,
        std::vector<std::vector<int>>& ans ) const
    {
        assert( target >= currSum );

        if( target == currSum )
        {
            ans.push_back(currCombination);
            return;
        }

        const auto SIZE = candidates.size();
        for( auto i=currCanIdx; i<SIZE; )
        {
            auto n = candidates.at(i);
            auto new_sum = currSum + n;
            if( target >= new_sum )
            {
                currCombination.push_back(n);
                BackTracking( candidates, target, new_sum, i+1, currCombination, ans );
                currCombination.pop_back();
            }

            while( (i<SIZE) && (n==candidates.at(i)) )
            {
                ++i;
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::sort( candidates.begin(), candidates.end() );

        std::vector<int> currCombination;
        std::vector<std::vector<int>> ans;
        BackTracking( candidates, target, 0, 0, currCombination, ans );

        return ans;
    }
};
