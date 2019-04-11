class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

    std::unordered_map<VALUE_TYPE, std::vector<SIZE_TYPE>> m_hash;

    const std::vector<int> NUMS;

public:
    Solution(vector<int>& nums) :
        NUMS(nums)
    {
        const auto SIZE = nums.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i ) m_hash[nums.at(i)].push_back(i);
    }

    int pick(int target)
    {
        std::random_device rd;
        std::default_random_engine gen = std::default_random_engine(rd());

        // Reservoir Sampling
        bool have_ans = false;
        SIZE_TYPE ans = 0;
        const auto SIZE = NUMS.size();
        for( SIZE_TYPE i=0, count=0; i<SIZE; ++i )
        {
            if( target == NUMS.at(i) )
            {
                ++count;

                std::uniform_int_distribution<int> dis(1, count);
                ans = dis(gen)==1 ? i: ans;
                have_ans = true;
            }
        }

        return have_ans ? ans : -1;

        // non Reservoir Sampling
//         if( !m_hash.count(target) ) return -1;

//         std::uniform_int_distribution<int> dis(0, m_hash[target].size()-1);

//         return m_hash[target].at(dis(gen));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
