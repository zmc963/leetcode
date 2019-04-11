class Solution
{
public:
    void combination( const std::string& prefix, std::size_t curr_digit_index, const string& digits, vector<string>& ans )
    {
        if( curr_digit_index >= digits.size() )
        {
            if( !prefix.empty() )
            {
                ans.push_back( prefix );
            }
            return ;
        }

        auto ctor = m_mappings.find( digits.at(curr_digit_index) );
        assert( m_mappings.end() != ctor );
        for( auto& letter : ctor->second )
        {
            combination( prefix + letter, curr_digit_index+1, digits, ans );
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        combination( "", 0, digits, ans );

        return ans;
    }

private:
    std::map<std::string::value_type, std::vector<std::string>> m_mappings =
        { { '2', {"a", "b", "c"} },
          { '3', {"d", "e", "f"} },
          { '4', {"g", "h", "i"} },
          { '5', {"j", "k", "l"} },
          { '6', {"m", "n", "o"} },
          { '7', {"p", "q", "r", "s"} },
          { '8', {"t", "u", "v"} },
          { '9', {"w", "x", "y", "z"} } };
};
