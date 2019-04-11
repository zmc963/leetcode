class Solution {
public:
    int minMoves(vector<int>& nums)
    {
        auto min_val = std::min_element( nums.begin(), nums.end() );
        int count = 0;
        for( auto n : nums ) count += n - *min_val;

        return count;
    }
};
