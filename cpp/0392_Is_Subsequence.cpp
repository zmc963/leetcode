class Solution
{
    using SIZE_TYPE = std::string::size_type;

public:
    bool isSubsequence( const std::string& s, const std::string& t )
    {
        const auto S_SIZE = s.size();
        const auto T_SIZE = t.size();

        SIZE_TYPE i = 0;
        for( SIZE_TYPE j=0; i<S_SIZE && j<T_SIZE; ++j )
        {
            if( s.at(i) == t.at(j) )
            {
                ++i;
            }
        }

        return S_SIZE==i;
    }
};
