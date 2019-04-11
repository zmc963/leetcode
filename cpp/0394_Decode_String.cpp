class Solution
{
    using SIZE_TYPE = std::string::size_type;

    std::string DecodeStringImp( const std::string& s, SIZE_TYPE& start ) const
    {
        const auto SIZE = s.size();
        assert( start <= SIZE );

        std::string res;
        for( int count=0; start<SIZE; ++start )
        {
            auto c = s.at(start);
            if( std::isdigit(c) )
            {
                auto end = start+1;
                while( end<SIZE && std::isdigit(s.at(end)) ) ++end;

                count = std::stoi( s.substr(start, end+1-start) );
                start = end - 1;
            }
            else if( '[' == c )
            {
                auto t = DecodeStringImp( s, ++start );

                while( count-- > 0 ) res += t;
                count = 0;
            }
            else if( ']' == c )
            {
                return res;
            }
            else
            {
                res += std::string(1, c);
            }
        }

        return res;
    }

public:
    string decodeString(string s)
    {
        SIZE_TYPE start = 0;
        return DecodeStringImp( s, start );
    }
};
