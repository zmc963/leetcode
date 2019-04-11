class Solution
{
    using DATA_TYPE = std::vector<int>;
    using SIZE_TYPE = DATA_TYPE::size_type;

    const DATA_TYPE::size_type SIZE;
    const DATA_TYPE NUMS;

public:
    Solution(vector<int> nums) :
        SIZE(nums.size())
       ,NUMS(nums)
    {}

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return NUMS;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        std::random_device rd;
        std::default_random_engine gen = std::default_random_engine(rd());

        auto shuffled_nums = NUMS;

        for( SIZE_TYPE i=SIZE-1; i<SIZE; --i )
        {
            std::uniform_int_distribution<int> dis(0, i);
            std::swap( shuffled_nums.at(dis(gen)), shuffled_nums.at(i) );
        }

        return shuffled_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
