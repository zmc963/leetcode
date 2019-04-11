class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::map<std::string, std::vector<std::string>> ans_map;
        for( auto s : strs )
        {
            auto ori_s = s;
            std::sort( s.begin(), s.end() );
            auto itr = ans_map.find( s );
            if( itr == ans_map.end() )
            {
                ans_map.insert( {s, {ori_s}} );
            }
            else
            {
                itr->second.push_back( ori_s );
            }
        }

        vector<vector<string>> ans;
        for( auto&& vec : ans_map )
        {
            ans.emplace_back( vec.second );
        }

        return ans;
    }
};
