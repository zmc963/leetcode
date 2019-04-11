/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LFUCache
{
    using KEY_TYPE = int;
    using VALUE_TYPE = int;
    using FREQ_TYPE = unsigned long long;

    using VALUE_DATA_TYPE = std::list<std::pair<VALUE_TYPE, KEY_TYPE>>;
    using FREQ_DATA_TYPE = std::unordered_map<FREQ_TYPE, VALUE_DATA_TYPE>;

    std::unordered_map<KEY_TYPE, FREQ_TYPE> m_hash;
    FREQ_DATA_TYPE m_freq;
    std::unordered_map<KEY_TYPE, VALUE_DATA_TYPE::iterator> m_freq_itr;

    int m_capacity;
    FREQ_TYPE m_min_freq;

public:
    LFUCache(int capacity) :
        m_capacity(capacity)
       ,m_min_freq(0)
    {}

    VALUE_TYPE get(KEY_TYPE key)
    {
        assert( m_freq_itr.size() == m_hash.size() );
        if( !m_hash.count(key) ) return -1;

        assert( key == m_freq_itr[key]->second );
        auto value = m_freq_itr[key]->first;

        auto old_freq = m_hash[key];
        m_freq[old_freq+1].splice( m_freq[old_freq+1].begin(), m_freq[old_freq], m_freq_itr[key] );
        ++m_hash[key];

        // note ++ works
        assert( m_freq.count(m_min_freq) );
        if( m_freq.at(m_min_freq).empty() )
        {
            m_freq.erase( m_min_freq );
            ++m_min_freq;
        }

//         {
//             std::cout << "get key: " << key << ", min_freq: " << m_min_freq << std::endl;
//             for( auto h : m_hash ) std::cout << "key: " << h.first << " : " << "freq: " << h.second << std::endl;

//             for( auto h : m_freq )
//             {
//                 std::cout << "freq: " << h.first << " : ";
//                 for( auto l : h.second ) std::cout << l.first << " ";
//                 std::cout << std::endl;
//             }

//             std::cout << std::endl;
//         }

        return value;
    }

    void put(KEY_TYPE key, VALUE_TYPE value)
    {
        assert( m_freq_itr.size() == m_hash.size() );
        if( m_capacity <= 0 ) return;

        // update value wit existed key
        if( -1 != get(key) )
        {
            m_freq_itr[key]->first = value;
            return;
        }
        // another strategy that the existed key/value is deleted and inserted afterwards
        // if( m_hash.count( key ) )
        // {
        //     m_freq[m_hash[key]].erase( m_freq_itr[key] );
        //     m_freq_itr.erase( key );
        //     m_hash.erase( key );
        // }

        if( m_hash.size() == m_capacity )
        {
            assert( m_freq.count(m_min_freq) && !m_freq[m_min_freq].empty() );
            auto to_be_erased_key = m_freq[m_min_freq].back().second;
            m_freq_itr.erase( to_be_erased_key );
            m_hash.erase( to_be_erased_key );

            m_freq[m_min_freq].pop_back();

            if( m_freq.at(m_min_freq).empty() ) m_freq.erase( m_min_freq );
        }

        FREQ_TYPE new_freq = 1;
        m_hash[key] = new_freq;
        m_freq[new_freq].emplace_front( value, key );
        m_freq_itr[key] = m_freq[new_freq].begin();
        m_min_freq = new_freq;

//         {
//             std::cout << "put key: " << key << ", value: " << value << ", min_freq: " << m_min_freq << std::endl;
//             for( auto h : m_hash ) std::cout << "key: " << h.first << " : " << "freq: " << h.second << std::endl;

//             for( auto h : m_freq )
//             {
//                 std::cout << "freq: " << h.first << " : ";
//                 for( auto l : h.second ) std::cout << l.first << " ";
//                 std::cout << std::endl;
//             }

//             std::cout << std::endl;
//         }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
