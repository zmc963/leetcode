class Solution
{
public:
    int minMoves2(vector<int>& nums)
    {
        if( nums.empty() ) return 0;

        const auto MID = nums.size()/2;
        std::nth_element( nums.begin(), nums.begin() + MID, nums.end()) ;
        auto mid = nums.at(MID);

        auto ans = 0;
        for( auto num : nums )
        {
            ans += abs(num - mid);
        }

        return ans;
    }
};
