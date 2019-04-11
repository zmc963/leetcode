class Solution
{
    using IDX_TYPE = std::string::size_type;
    using VAL_TYPE = std::string::value_type;

    // stack overflow
    int DC( const std::string& s, IDX_TYPE begin, IDX_TYPE end ) const
    {
        assert( begin <= s.size() );
        assert( end <= s.size() );
        if( begin >= end )
        {
            assert( begin == end );
            return 0;
        }

        std::unordered_map<VAL_TYPE, IDX_TYPE> hash;
        for( IDX_TYPE i=begin; i<end; ++i )
        {
            auto c = s.at(i);
            auto itr = hash.find(c);
            if( hash.end() != itr )
            {
                return std::max( DC( s, begin, i ), DC( s, itr->second+1, end ) );
            }

            hash.insert( {c, i} );
        }

        return end-begin;
    }

public:
    int lengthOfLongestSubstring(string s)
    {
        IDX_TYPE left = 0;

        const auto SIZE = s.size();
        std::unordered_map<VAL_TYPE, IDX_TYPE> hash;
        IDX_TYPE max_len = 0;
        for( IDX_TYPE right=0; right<SIZE; ++right )
        {
            auto c = s.at(right);
            auto itr = hash.find(c);
            if( hash.end() != itr )
            {
                left = std::max( left, itr->second+1 );
            }

            hash[c] = right;
            max_len = std::max( max_len, right-left+1 );
        }

        return max_len;
    }

    int BadlengthOfLongestSubstring(string s)
    {
        stack<std::pair<IDX_TYPE, IDX_TYPE>> search_range;
        search_range.push( {0, s.size()} );

        IDX_TYPE max_len = 0;
        while( !search_range.empty() )
        {
            auto range = search_range.top();
            auto begin = range.first;
            auto end = range.second;
            search_range.pop();

            assert( begin <= s.size() );
            assert( end <= s.size() );

            std::unordered_map<VAL_TYPE, IDX_TYPE> hash;
            for( IDX_TYPE i=begin; i<end; ++i )
            {
                auto c = s.at(i);
                auto itr = hash.find(c);
                if( hash.end() != itr )
                {
                    if( begin < i ) search_range.push( {begin, i} );
                    if( (itr->second+1) < end ) search_range.push( {itr->second+1, end} );

                    end = begin;
                    break;
                }

                hash.insert( {c, i} );
            }

            max_len = std::max( max_len, end-begin );
        }

        return max_len;
    }
};
