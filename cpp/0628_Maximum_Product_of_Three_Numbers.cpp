class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
        if( nums.size() < 3 ) return 0;

        std::priority_queue<int, std::vector<int>, std::greater<int>> max_pq;
        std::priority_queue<int, std::vector<int>, std::less<int>> min_pq;

        for( auto n : nums )
        {
            max_pq.push(n);
            min_pq.push(n);

            if( max_pq.size() > 3 ) max_pq.pop();
            if( max_pq.size() > 2 ) min_pq.pop();
        }

        auto max_val = 1;
        while( !max_pq.empty() )
        {
            max_val *= max_pq.top();
            max_pq.pop();
        }

        auto min_val = 1;
        while( !min_pq.empty() )
        {
            min_val *= min_pq.top();
            min_pq.pop();
        }

        return std::max( max_val, min_val*max_pq.top() );
    }
};
