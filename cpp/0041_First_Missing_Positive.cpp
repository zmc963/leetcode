class Solution
{
    using IDX_TYPE = std::vector<int>::size_type;
public:
    int firstMissingPositive(vector<int>& nums)
    {
        const auto SIZE = nums.size();
        for( IDX_TYPE i=0; i<SIZE; ++i )
        {
            while( (nums.at(i)<SIZE) && (nums.at(i)>0) && (nums.at(i)!=nums.at(nums.at(i)-1)) )
            {
                std::swap( nums.at(i), nums.at(nums.at(i)-1) );
            }
        }

        for( IDX_TYPE i=0; i<SIZE; ++i )
        {
            if( (i+1) != nums.at(i) )
            {
                return i+1;
            }
        }

        return SIZE+1;
    }
};
