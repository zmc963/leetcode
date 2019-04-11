class RandomizedCollection
{
    using SIZE_TYPE = std::vector<int>::size_type;

    std::vector<std::pair<int, SIZE_TYPE>> m_data;
    std::unordered_map<int, std::vector<SIZE_TYPE>> m_hash;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        bool is_already_existed = m_hash.count(val);
        assert( (is_already_existed&&!m_hash[val].empty()) || !is_already_existed);

        m_hash[val].push_back( m_data.size() );
        m_data.emplace_back( val, m_hash[val].size()-1 );

        return !is_already_existed;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if( !m_hash.count(val) ) return false;

        auto remove_data_idx = m_hash[val].back();
        auto last_data = m_data.back();

        m_data.at(remove_data_idx) = last_data;
        m_hash[last_data.first].at(last_data.second) = remove_data_idx;

        m_hash[val].pop_back();
        if( m_hash[val].empty() ) m_hash.erase(val);
        m_data.pop_back();

        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        std::random_device rd;
        std::default_random_engine gen = std::default_random_engine(rd());
        std::uniform_int_distribution<int> dis(0, m_data.size()-1);

        return m_data.at(dis(gen)).first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
