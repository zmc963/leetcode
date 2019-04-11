class Solution
{
    using IDX_TYPE = std::string::size_type;

    // 0: reach the end of s but unmatched
    // 1: unmatched without reaching the end of s
    // 2: matched
    enum class RST { MATCHED, NOT_MATCHED_STOP, NOT_MATCHED_CONTINUE };
    RST WildcardMatching( const std::string& s, const std::string& p, IDX_TYPE sIdx, IDX_TYPE pIdx ) const
    {
        assert( sIdx <= s.size() );
        assert( pIdx <= p.size() );
        bool is_s_end = (sIdx == s.size());
        bool is_p_end = (pIdx == p.size());

        //std::cout << sIdx << " " << pIdx << std::endl;

        if( is_p_end && is_s_end ) return RST::MATCHED;
        if( is_s_end and ('*' != p.at(pIdx)) ) return RST::NOT_MATCHED_STOP;
        if( is_p_end ) return RST::NOT_MATCHED_CONTINUE;

        auto curr_p = p.at(pIdx);
        if( '*' == curr_p )
        {
            IDX_TYPE new_p_idx = pIdx+1;
            while( (new_p_idx<p.size()) && ('*'==p.at(new_p_idx)) ) ++new_p_idx;

            // 0 ~ many
            auto res = WildcardMatching( s, p, sIdx, new_p_idx );
            if( (RST::MATCHED==res) || (RST::NOT_MATCHED_STOP==res) ) return res;

            assert( !is_s_end );
            return WildcardMatching( s, p, sIdx+1, new_p_idx-1 );
        }
        else if( !is_s_end && (('?' == curr_p) || (curr_p==s.at(sIdx))) )
        {
            return WildcardMatching( s, p, sIdx+1, pIdx+1 );
        }

        return RST::NOT_MATCHED_CONTINUE;
    }

public:
    bool isMatch(string s, string p)
    {
        return (RST::MATCHED==WildcardMatching( s, p, 0, 0 )) ? true : false;

        const auto S_SIZE = s.size();
        const auto P_SIZE = p.size();

        std::vector<std::vector<bool>> dp(S_SIZE+1);

        for( auto& v : dp ) v.resize( P_SIZE+1, false );
        dp.at(0).at(0) = true;
        for( IDX_TYPE j=0; j<P_SIZE; ++j )
        {
            if( p.at(j) == '*' ) dp.at(0).at(j+1) = dp.at(0).at(j);
        }

        for( IDX_TYPE i=1; i<=S_SIZE; ++i )
        {
            auto curr_s = s.at(i-1);
            for( IDX_TYPE j=1; j<=P_SIZE; ++j )
            {
                auto curr_p = p.at(j-1);
                if( '*' == curr_p )
                {
                    dp.at(i).at(j) = dp.at(i-1).at(j) || dp.at(i).at(j-1);
                }
                else
                {
                    dp.at(i).at(j) = dp.at(i-1).at(j-1) && (('?' == curr_p) || (curr_p==curr_s));
                }
            }
        }

        return dp.back().back();
    }
};
