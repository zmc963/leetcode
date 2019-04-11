class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

    bool IsValidConnection( const std::string& start, const std::string& end ) const
    {
        assert( !start.empty() && start.size()==end.size() );

        const auto SIZE = start.size();

        SIZE_TYPE count_diff = 0;
        for( SIZE_TYPE i=0; i<SIZE&&count_diff<=1; ++i )
        {
            if( start.at(i) != end.at(i) ) ++count_diff;
        }

        return count_diff==1;
    }

public:
    int minMutation(string start, string end, vector<string>& bank)
    {
        const auto SIZE = bank.size();

        std::unordered_map<std::string, std::unordered_set<std::string>> graph;
        for( auto&& g1 : bank )
        {
            if( IsValidConnection(start, g1) ) graph[start].insert(g1);
            for( auto&& g2 : bank )
            {
                if( IsValidConnection(g1, g2) )
                {
                    graph[g1].insert(g2);
                    graph[g2].insert(g1);
                }
            }
        }
        assert( graph.size() <= bank.size()+1 );

        // BFS
        std::queue<std::string> gene_queue;
        gene_queue.push(start);

        int min_path_len = 0;
        std::unordered_set<std::string> visit;
        while( !gene_queue.empty() )
        {
            const auto SIZE = gene_queue.size();

            ++min_path_len;
            for( SIZE_TYPE i=0; i<SIZE; ++i )
            {
                auto curr = gene_queue.front();
                gene_queue.pop();

                visit.insert(curr);
                if( end == curr ) return min_path_len-1; // minus start

                for( auto&& n : graph[curr] )
                {
                    //if( n == end ) return min_path_len+1;
                    if( !visit.count(n) ) gene_queue.push(n);
                }
            }
        }

        assert( visit.size()==graph.size() );
        return -1;
    }
};
