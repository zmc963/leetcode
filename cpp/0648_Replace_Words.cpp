class Solution
{
    static constexpr auto R = 26;

    struct TrieNode
    {
        bool m_is_key = false;
        std::unique_ptr<TrieNode> m_child[Solution::R];
    };

    void BuildTrie( const std::vector<std::string>& dict, std::unique_ptr<TrieNode>& root ) const
    {
        assert( root );

        for( auto&& d : dict )
        {
            auto curr = root.get();
            for( auto&& c : d )
            {
                auto idx = c - 'a';
                assert( 0<=idx && idx<Solution::R );

                if( !curr->m_child[idx] ) curr->m_child[idx] = std::make_unique<TrieNode>();

                curr = curr->m_child[idx].get();
            }

            curr->m_is_key = true;
        }
    }

    std::string Search( TrieNode* root, const std::string& word ) const
    {
        std::string matched;
        for( auto&& c : word )
        {
            auto idx = c - 'a';
            assert( 0<=idx && idx<Solution::R );

            if( !root->m_child[idx] || root->m_is_key ) break;

            root = root->m_child[idx].get();

            matched += c;
        }

        return root->m_is_key ? matched : "";
    }

public:
    string replaceWords( std::vector<std::string>& dict, std::string sentence )
    {
        auto root = std::make_unique<TrieNode>();
        BuildTrie( dict, root );

        std::istringstream is(sentence);
        std::string ans;

        std::string word;
        while( is >> word )
        {
            if( is.fail() ) break;

            auto matched = Search( root.get(), word );

            ans += matched.empty() ? word + " " : matched + " ";
        }

        if( !ans.empty() ) ans.pop_back();

        return ans;
    }
};
