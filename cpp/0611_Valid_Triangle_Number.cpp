class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int triangleNumber(vector<int>& nums)
    {
        const auto SIZE = nums.size();
        SIZE_TYPE cnt = 0;

        std::sort( nums.begin(), nums.end() );
        for( SIZE_TYPE i=SIZE-1; i<SIZE; --i )
        {
            auto max_num = nums.at(i);

            SIZE_TYPE left = 0;
            SIZE_TYPE right = i-1;

            while( right<SIZE && left<right )
            {
                auto min_num = nums.at(left);
                auto middle_num = nums.at(right);

                if( min_num+middle_num <= max_num )
                {
                    ++left;
                }
                else if( min_num+middle_num > max_num )
                {
                    cnt += right - left;
                    --right;
                }
            }
        }

        return cnt;
    }
};
