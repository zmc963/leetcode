class LRUCache
{
    using KEY_TYPE = int;
    using VALUE_TYPE = int;
    using DATA_TYPE = std::list<std::pair<VALUE_TYPE, KEY_TYPE>>;

    std::unordered_map<KEY_TYPE, DATA_TYPE::iterator> m_hash;
    DATA_TYPE m_val;

    int m_capacity;

public:
    LRUCache(int capacity) :
        m_capacity(capacity)
    {}

    VALUE_TYPE get(KEY_TYPE key)
    {
        assert( m_val.size() == m_hash.size() );

        if( !m_hash.count(key) ) return -1;

        assert( (*m_hash[key]).second == key );

        m_val.splice( m_val.begin(), m_val, m_hash[key] );
        assert( m_hash[key] == m_val.begin() );

        return m_val.front().first;
    }

    void put(KEY_TYPE key, VALUE_TYPE value)
    {
        assert( m_val.size() == m_hash.size() );
        if( m_capacity <= 0 ) return;

        auto find_itr = m_hash.find(key);
        if( m_hash.end() != find_itr )
        {
            m_val.erase( find_itr->second );
            // m_hash.erase( find_itr );      // m_hash[key] would be updated late eventually, no need to so here
        }

        if( m_val.size() == m_capacity )
        {
            auto&& to_be_erased_key = m_val.back().second;
            m_hash.erase(to_be_erased_key);
            m_val.pop_back();
        }

        m_val.emplace_front( value, key );
        m_hash[key] = m_val.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
