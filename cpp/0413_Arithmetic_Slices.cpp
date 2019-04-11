class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    int numberOfArithmeticSlices(vector<int>& A)
    {
        // 2 ptrs
        if( A.size() < 3 ) return 0;

        auto count = 0;
        const auto SIZE = A.size();
        for( SIZE_TYPE left=0, right=1, check_diff=A.at(right)-A.at(left); right<SIZE; ++right )
        {
            auto curr_diff = A.at(right) - A.at(right-1);
            if( curr_diff == check_diff )
            {
                auto len = right - left + 1;
                if( len >= 3 )
                {
                    count += len-2;
                }
            }
            else
            {
                check_diff = curr_diff;
                left = right-1;
            }
        }

        return count;
    }
};
