class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if( nums.empty() )
        {
            return 0;
        }

        const auto SIZE = nums.size();
        std::vector<int>::size_type tail = 0;
        for( std::vector<int>::size_type i=1; i<SIZE; ++i )
        {
            if( nums.at(i) > nums.at(tail) )
            {
                ++tail;
                std::swap( nums.at(i), nums.at(tail) );
            }
        }

        return 1+tail;
    }
};

