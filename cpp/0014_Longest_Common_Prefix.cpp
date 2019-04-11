class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if( strs.empty() )
        {
            return "";
        }

        std::string common_prefix;
        const auto P_SIZE = strs.front().size();
        const auto S_SIZE = strs.size();
        for( std::string::size_type i=0; i<P_SIZE; ++i )
        {
            auto c = strs.front().at(i);
            for( std::vector<std::string>::size_type j=0; j<S_SIZE; ++j )
            {
                if( i >= strs.at(j).size() || c != strs.at(j).at(i) )
                {
                    return common_prefix;
                }
            }

            common_prefix += c;
        }

        return common_prefix;
    }
};
