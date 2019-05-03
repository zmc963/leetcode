class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    int countBinarySubstrings(string s)
    {
        const auto SIZE = s.size();
        SIZE_TYPE cnt = 0;

        for( SIZE_TYPE i=1, curr=1, prev=0; i<SIZE; ++i )
        {
            if( s.at(i-1) != s.at(i) )
            {
                prev = curr;
                curr = 1;
            }
            else
            {
                ++curr;
            }

            if( prev >= curr ) ++cnt;
        }

        return cnt;
    }
};

