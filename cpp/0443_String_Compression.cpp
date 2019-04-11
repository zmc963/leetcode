class Solution
{
    using SIZE_TYPE = std::vector<char>::size_type;
    using VALUE_TYPE = std::vector<char>::value_type;

public:
    int compress(vector<char>& chars)
    {
        const auto SIZE = chars.size();

        SIZE_TYPE start = 0;
        for( SIZE_TYPE end=0; end<SIZE; )
        {
            VALUE_TYPE curr_c = chars.at(end);
            auto check_start = end;
            while( end<SIZE && curr_c==chars.at(end) ) ++end;

            SIZE_TYPE count = end - check_start;
            chars.at(start) = curr_c;
            ++start;

            if( count >= 2 )
            {
                for( auto c : std::to_string(count) )
                {
                    chars.at(start) = c;
                    ++start;
                }
            }
        }

        return start;
    }
};

