class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    bool find132pattern(vector<int>& nums)
    {
        std::vector<int> min_val;
        for( auto n : nums )
        {
            min_val.push_back( min_val.empty() ? n : std::min( n, min_val.back() ) );
        }

        std::stack<int> k_stack;
        const auto SIZE = nums.size();
        for( SIZE_TYPE j=SIZE-1; j<SIZE; --j )
        {
            while( !k_stack.empty() && k_stack.top()<=min_val.at(j) )
            {
                k_stack.pop();
            }

            if( !k_stack.empty() && k_stack.top()<nums.at(j) ) return true;

            k_stack.push( nums.at(j) );
        }

        return false;
    }
};
