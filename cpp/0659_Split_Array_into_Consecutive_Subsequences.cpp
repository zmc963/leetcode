class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    bool isPossible(vector<int>& nums)
    {
        std::unordered_map<int, SIZE_TYPE> freq;
        std::unordered_map<int, int> need;

        for( auto num : nums ) ++freq[num];

        for( auto num : nums )
        {
            assert( freq.count(num) );

            if( freq[num] == 0 ) continue;
            else if( need.count(num) && need.at(num)>0 )
            {
                --need[num];
                ++need[num + 1];
            }
            else if( freq.count(num+1) && freq[num+1]>0 && freq.count(num+2) && freq[num+2]>0 )
            {
                --freq[num + 1];
                --freq[num + 2];
                ++need[num + 3];
            }
            else return false;

            --freq[num];
        }

        return true;
    }
};
