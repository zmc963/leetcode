class Solution
{
    using VALUE_TYPE = int;
    using SIZE_TYPE = std::vector<VALUE_TYPE>::size_type;

    struct Info
    {
        SIZE_TYPE m_cnt = 0;
        SIZE_TYPE m_min_idx = std::numeric_limits<SIZE_TYPE>::max();
        SIZE_TYPE m_max_idx = std::numeric_limits<SIZE_TYPE>::min();
    };

public:
    int findShortestSubArray(vector<VALUE_TYPE>& nums)
    {
        std::unordered_map<VALUE_TYPE, Info> hash;

        const auto SIZE = nums.size();
        SIZE_TYPE max_cnt = 0;
        SIZE_TYPE min_len = SIZE;

        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            auto& h = hash[nums.at(i)];

            ++h.m_cnt;
            h.m_min_idx = std::min( h.m_min_idx, i );
            h.m_max_idx = i;

            if( max_cnt < h.m_cnt )
            {
                max_cnt = h.m_cnt;
                min_len = h.m_max_idx - h.m_min_idx + 1;
            }
            else if( max_cnt == h.m_cnt )
            {
                min_len = std::min( min_len,  h.m_max_idx - h.m_min_idx + 1 );
            }
        }

        return min_len;
    }
};
