class Solution
{
    using SIZE_TYPE = std::string::size_type;

    bool IsFirstASubSeqOfSecond( const std::string& first, const std::string& second ) const
    {
        SIZE_TYPE matched = 0;

        for( auto&& c : second )
        {
            if( c == first.at(matched) ) ++matched;
            if( first.size() == matched ) return true;
        }

        return false;
    }

public:
    string findLongestWord(string s, vector<string>& d)
    {
        std::sort( d.begin(), d.end(), []( const auto& left, const auto& right )
            {
                return left.size()==right.size() ? left<right : left.size()>right.size();
            } );

        for( auto&& w : d )
        {
            if( IsFirstASubSeqOfSecond( w, s ) ) return w;
        }

        return {};
    }
};
