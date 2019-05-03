class Solution
{
    using PQ_VALUE_TYPE = std::pair<int, int>;
    using SIZE_TYPE = std::vector<int>::size_type;

    struct PQCmp
    {
    public:
        bool operator()( const PQ_VALUE_TYPE& left, const PQ_VALUE_TYPE& right ) const
        {
            return left.second > right.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> hash;
        for( auto i : nums ) ++hash[i];

        std::priority_queue<PQ_VALUE_TYPE, std::vector<PQ_VALUE_TYPE>, PQCmp> pq;
        for( auto&& h : hash )
        {
            pq.push(h);
            if( pq.size() > k ) pq.pop();
        }

        std::vector<int> ans;
        while( !pq.empty() )
        {
            ans.push_back( pq.top().first );
            pq.pop();
        }

        return std::vector( ans.rbegin(), ans.rend() );
    }
};
