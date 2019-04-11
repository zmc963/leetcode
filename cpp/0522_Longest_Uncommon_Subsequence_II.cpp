class Solution
{
    using STR_SIZE_TYPE = std::string::size_type;
    using VEC_SIZE_TYPE = std::string::size_type;

    bool IsFirstUSofSecond( const std::string& first, const std::string& second ) const
    {
        if( first.size() > second.size() ) return true;

        STR_SIZE_TYPE matched = 0;
        for( auto c : second )
        {
            if( c == first.at(matched) ) ++matched;
            if( matched == first.size() ) break;
        }

        return matched != first.size();
    }

public:
    int findLUSlength(vector<string>& strs)
    {
        STR_SIZE_TYPE max_len = 0;
        const auto SIZE = strs.size();
        for( VEC_SIZE_TYPE i=0; i<SIZE; ++i )
        {
            VEC_SIZE_TYPE j = 0;
            for( ; j<SIZE; ++j )
            {
                if( i == j ) continue;
                if( !IsFirstUSofSecond(strs.at(i), strs.at(j)) ) break;
            }

            if( j == SIZE ) max_len = std::max( max_len, strs.at(i).size() );
        }

        return max_len==0 ? -1 : max_len;
    }
};
