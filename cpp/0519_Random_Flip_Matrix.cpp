class Solution
{
    int m_rows;
    int m_cols;

    int m_size;
    std::unordered_map<int, int> m_hash;

public:
    Solution(int n_rows, int n_cols) :
         m_rows(n_rows)
        ,m_cols(n_cols)
        ,m_size(m_rows*m_cols)
    {}

    vector<int> flip()
    {
        if( 0 == m_size ) return {};

        std::random_device rd;
        std::default_random_engine gen = std::default_random_engine(rd());
        std::uniform_int_distribution<int> dis(0, m_size-1);

        auto idx = dis(gen);
        auto t_idx = idx;
        --m_size;
        if( m_hash.count(idx) )
        {
            idx = m_hash[idx];
        }

        m_hash[t_idx] = m_hash.count(m_size) ? m_hash[m_size] : m_size;

        return { idx/m_cols, idx%m_cols };
    }


    void reset()
    {
        m_hash.clear();
        m_size = m_rows*m_cols;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
