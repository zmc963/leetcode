class Solution
{
    using VALUE_TYPE = std::string::value_type;

public:
    vector<string> findWords(vector<string>& words)
    {
        const std::unordered_map<VALUE_TYPE, int> GROUP =
        {
            { 'Q', 1 },
            { 'W', 1 },
            { 'E', 1 },
            { 'R', 1 },
            { 'T', 1 },
            { 'Y', 1 },
            { 'U', 1 },
            { 'I', 1 },
            { 'O', 1 },
            { 'P', 1 },

            { 'A', 2 },
            { 'S', 2 },
            { 'D', 2 },
            { 'F', 2 },
            { 'G', 2 },
            { 'H', 2 },
            { 'J', 2 },
            { 'K', 2 },
            { 'L', 2 },

            { 'Z', 3 },
            { 'X', 3 },
            { 'C', 3 },
            { 'V', 3 },
            { 'B', 3 },
            { 'N', 3 },
            { 'M', 3 },
        };
        assert( GROUP.size() == 26 );

        std::vector<std::string> ans;
        for( auto&& s : words )
        {
            ans.push_back(s);
            auto old_group_idx = -1;
            for( auto c : s )
            {
                auto group_idx = GROUP.at(std::toupper(c));
                if( -1!=old_group_idx && old_group_idx!=group_idx )
                {
                    ans.pop_back();
                    break;
                }

                old_group_idx = group_idx;
            }
        }

        return ans;
    }
};
