class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
        std::unordered_map<std::string, std::vector<std::string>> hash;
        for( auto&& p : paths )
        {
            std::istringstream is(p);

            std::string path;
            is >> path;

            std::string file;
            while( is >> file )
            {
                assert( !file.empty() );

                auto idx = file.find_last_of('(');
                assert( string::npos != idx );
                std::string file_name = file.substr( 0, idx );
                std::string file_content = file.substr( idx+1, file.size()-idx-2 );

                hash[file_content].push_back( path + "/" + file_name );
            }
        }

        std::vector<std::vector<std::string>> ans;
        for( auto&& h : hash )
        {
            if( h.second.size() > 1 )
            {
                ans.emplace_back( std::move(h.second) );
            }
        }

        return ans;
    }
};
