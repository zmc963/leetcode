class MapSum
{
    static constexpr auto R = 256; // ASCII

    struct TrieNode
    {
        int m_sum = 0;
        bool m_is_key = false;

        std::unique_ptr<TrieNode> m_children[MapSum::R];
    };

    std::unique_ptr<TrieNode> m_root;
    std::unordered_map<std::string, int> m_hash;

//     int TraversalSum( TrieNode* root ) const
//     {
//         if( !root ) return 0;

//         auto sum = 0;
//         for( auto&& children : root->m_children )
//         {
//             sum += TraversalSum( children.get() );
//         }

//         return sum + (root->m_is_key ? root->m_val : 0);
//     }

public:
    /** Initialize your data structure here. */
    MapSum() :
        m_root(std::make_unique<TrieNode>())
    {}

    void insert( std::string key, int val )
    {
        auto offset = val;
        if( m_hash.count(key) ) offset = val - m_hash[key];
        m_hash[key] = val;

        auto curr = m_root.get();
        for( auto c : key )
        {
            if( c >= MapSum::R ) return;

            if( !curr->m_children[c] )
            {
                curr->m_children[c] = std::make_unique<TrieNode>();
                curr = curr->m_children[c].get();

                curr->m_sum += val;
            }
            else
            {
                curr = curr->m_children[c].get();

                curr->m_sum += offset;
            }
        }

        assert( curr );
        curr->m_is_key = true;
    }

    int sum( std::string prefix )
    {
        auto curr = m_root.get();
        for( auto c : prefix )
        {
            if( c>=MapSum::R || !curr->m_children[c] ) return 0;

            curr = curr->m_children[c].get();
            // std::cout << curr->m_sum << std::endl;
        }

        return curr->m_sum ;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
