class Solution
{
    using IDX_TYPE = std::string::size_type;

public:
    bool isMatch(string s, string p)
    {
        return RegexMatch( s, 0, p, 0 );
    }

private:
    bool RegexMatch(
        const std::string& s,
        IDX_TYPE currSIdx,
        const std::string& p,
        IDX_TYPE currPIdx ) const
    {
        // std::cout << currSIdx << " " << currPIdx << std::endl;
        const auto S_SIZE = s.size();
        const auto P_SIZE = p.size();

        auto is_s_end = (S_SIZE == currSIdx);
        auto is_p_end = (P_SIZE == currPIdx);
        if( is_s_end && is_p_end )
        {
            return true;
        }
        else if( !is_s_end && is_p_end )
        {
            return false;
        }

        assert( currSIdx <= s.size() );
        assert( currPIdx < p.size() );

        auto curr_p = p.at(currPIdx);
        bool first_match = !is_s_end && (('.'==curr_p) || (s.at(currSIdx)==curr_p));

        if( (P_SIZE>(currPIdx+1)) && ('*'==p.at(currPIdx+1)) )
        {
            return RegexMatch( s, currSIdx, p, currPIdx+2 ) ||
                   (first_match && RegexMatch( s, currSIdx+1, p, currPIdx ));

//             // zero
//             if( RegexMatch( s, currSIdx, p, currPIdx+2 ) )
//             {
//                 return true;
//             }

//             // 1 ~ many
//             while( S_SIZE > currSIdx )
//             {
//                 if( !(('.'==curr_p) || (s.at(currSIdx)==curr_p)) )
//                 {
//                     return false;
//                 }

//                 ++currSIdx;
//                 if( RegexMatch( s, currSIdx, p, currPIdx+2 ) )
//                 {
//                     return true;
//                 }
//             }
//             return false;
        }

        return first_match && RegexMatch( s, currSIdx+1, p, currPIdx+1 );
    }
};
