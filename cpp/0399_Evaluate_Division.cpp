class Solution
{
    using SIZE_TYPE = vector<pair<string, string>>::size_type;

    bool BFS(
        const std::unordered_map<std::string, std::unordered_map<std::string, double>>& graph,
        const std::string& start,
        const std::string& target,
        double& ans ) const
    {
        if( !graph.count(start) || !graph.count(target) ) return false;

        std::unordered_set<std::string> visit;
        std::queue<std::pair<std::string, double>> state_queue;
        state_queue.emplace( start, 1.0 );
        visit.insert(start);

        while( !state_queue.empty() )
        {
            auto curr = state_queue.front();
            state_queue.pop();

            for( const auto& next : graph.at(curr.first) )
            {
                auto curr_res = curr.second * next.second;
                if( next.first == target )
                {
                    ans = curr_res;
                    return true;
                }
                else if( !visit.count(next.first) )
                {
                    state_queue.emplace( next.first, curr_res );
                    visit.insert(next.first);
                }
            }
        }

        return false;
    }

public:
    vector<double> calcEquation(
        const vector<pair<string, string>>& equations,
        vector<double>& values,
        const vector<pair<string, string>>& queries)
    {
        assert( equations.size() == values.size() );

        const auto EQUATION_SIZE = equations.size();
        std::unordered_map<std::string, std::unordered_map<std::string, double>> graph;

        for( SIZE_TYPE i=0; i<EQUATION_SIZE; ++i )
        {
            assert( !graph[equations.at(i).first].count(equations.at(i).second) );

            if( equations.at(i).second != equations.at(i).first )
            {
                graph[equations.at(i).second][equations.at(i).first] = values.at(i);
                graph[equations.at(i).first][equations.at(i).second] = 1.0 / values.at(i);
            }

            graph[equations.at(i).first][equations.at(i).first] = 1.0;
            graph[equations.at(i).second][equations.at(i).second] = 1.0;
        }

        std::vector<double> res;
        const auto QUERY_SIZE = queries.size();
        for( SIZE_TYPE i=0; i<QUERY_SIZE; ++i )
        {
            std::unordered_map<std::string, Color> visit;
            double ans = 1.0;
            if( BFS( graph, queries.at(i).second, queries.at(i).first, ans ) )
            {
                res.push_back(ans);
            }
            else
            {
                res.push_back(-1.0);
            }
        }

        return res;
    }
};
