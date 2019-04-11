class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;
    using VALUE_TYPE = std::vector<int>::value_type;

    SIZE_TYPE GetIndex( const vector<int>& nums, SIZE_TYPE curr ) const
    {
        assert( curr < nums.size() );

        const auto SIZE = nums.size();
        auto step = nums.at(curr);

        if( step < 0 )
        {
            step = (-(step+1)) % SIZE;
            step = SIZE - (step+1);
        }

        return (curr+step) % SIZE;
    }

    bool IsSameDirection( VALUE_TYPE start, VALUE_TYPE next ) const
    {
        return ((start>0&&next>0) || (start<0&&next<0));
    }

public:
    bool circularArrayLoop( std::vector<int>& nums ) const
    {
        const auto VISITED = 0;
        const auto SIZE = nums.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            for( SIZE_TYPE slow=i, fast=GetIndex(nums, i);
                 IsSameDirection(nums.at(i), nums.at(GetIndex(nums, fast))) && IsSameDirection(nums.at(i), nums.at(fast));
                 slow=GetIndex(nums, slow), fast=GetIndex(nums, GetIndex(nums, fast)) )
            {
                if( slow == fast )
                {
                    // cycle len > 1
                    if( GetIndex( nums, slow ) != slow ) return true;

                    break;
                }
            }

            // loop not found, set all element along the way to 0
            auto originl_val = nums.at(i);
            auto next = i;
            while( IsSameDirection(originl_val, nums.at(next)) )
            {
                auto next_backup = next;
                next = GetIndex( nums, next );
                nums.at(next_backup) = VISITED;
            }
        }

        return false;
    }
};
