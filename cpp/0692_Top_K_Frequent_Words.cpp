class Solution
{
    using SIZE_TYPE = std::vector<std::string>::size_type;
    using PQ_VALUE_TYPE = std::pair<std::string, SIZE_TYPE>;

    struct PQComp
    {
        bool operator()( const PQ_VALUE_TYPE& left, const PQ_VALUE_TYPE& right ) const
        {
            return left.second==right.second ? left<right : left.second>right.second;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        if( k < 0 ) return {};

        std::unordered_map<std::string, SIZE_TYPE> hash;
        for( auto&& w : words ) ++hash[w];

        std::priority_queue<PQ_VALUE_TYPE, std::vector<PQ_VALUE_TYPE>, PQComp> pq;
        for( auto&& h : hash )
        {
            pq.emplace( h.first, h.second );

            if( pq.size() > k ) pq.pop();
        }

        std::vector<std::string> ans( std::min(words.size(), static_cast<SIZE_TYPE>(k)) );
        const auto SIZE = ans.size();
        for( SIZE_TYPE i=SIZE-1; i<SIZE; --i )
        {
            ans.at(i) = pq.top().first;
            pq.pop();
        }

        return ans;
    }
};
