class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    bool checkPossibility(vector<int>& nums)
    {
        if( nums.empty() ) return true;

        const auto SIZE = nums.size();

        auto prev = nums.front();
        for( SIZE_TYPE i=1, cnt=0; i<SIZE; ++i )
        {
            if( nums.at(i) < prev )
            {
                if( ++cnt > 1 ) return false;

                if( i>=2 && nums.at(i-2)>nums.at(i) ) continue;
            }

            prev = nums.at(i);
        }

        return true;
    }
};
