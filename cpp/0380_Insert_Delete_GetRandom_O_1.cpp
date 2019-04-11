class RandomizedSet
{
    using DATA_TYPE = std::vector<int>;
    using SIZE_TYPE = DATA_TYPE::size_type;

    DATA_TYPE m_data;
    std::unordered_map<int, SIZE_TYPE> m_hash;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if( !m_hash.count(val) )
        {
            m_data.push_back(val);
            m_hash[val] = m_data.size()-1;

            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if( m_hash.count(val) )
        {
            auto remove_data_idx = m_hash[val];
            auto last_data = m_data.back();

            m_data.at(remove_data_idx) = last_data;
            m_hash[last_data] = remove_data_idx;

            m_hash.erase(val);
            m_data.pop_back();

            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        std::random_device rd;
        std::default_random_engine gen = std::default_random_engine(rd());
        std::uniform_int_distribution<int> dis(0, m_data.size()-1);

        return m_data.at(dis(gen));
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
