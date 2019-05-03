class Solution
{
    enum Color { GRAY, BLACK };

    bool DFS(
        const std::unordered_map<int, std::vector<int>>& graph,
        int prev,
        int curr,
        std::unordered_map<int, Color>& visited,
        std::vector<int>& ans ) const
    {
        assert( graph.count(curr) );
        assert( !visited.count(curr) );

        visited[curr] = Color::GRAY;
        for( auto&& neighbor : graph.at(curr) )
        {
            if( !visited.count(neighbor) )
            {
                if( !DFS( graph, curr, neighbor, visited, ans ) ) return false;
            }
            else if( prev!=neighbor && Color::GRAY==visited[neighbor] )
            {
                return false;
                // ans.emplace_back( std::min(curr, neighbor) );
                // ans.emplace_back( std::max(curr, neighbor) );
            }
        }

        visited[curr] = Color::BLACK;
        return true;
    }

    int GetRoot( int index, std::unordered_map<int, int>& root ) const
    {
        while( root.count(index) )
        {
            if( root.count(root.at(index)) ) root.at(index) = root.at(root.at(index));
            index = root.at(index);
        }

        return index;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
//         if( edges.empty() ) return {};

//         std::unordered_map<int, std::vector<int>> graph;

//         for( auto&& e : edges )
//         {
//             if( 2 != e.size() ) continue;

//             graph[e.front()].push_back( e.back() );
//             graph[e.back()].push_back( e.front() );

//             std::vector<int> ans;
//             std::unordered_map<int, Color> visited;

//             // must start from newly added edge
//             if( !DFS( graph, -1, e.front(), visited, ans ) ) return e;
//         }

//         return {};

        std::unordered_map<int, int> root;
        std::unordered_map<int, int> size;
        for( auto&& e : edges )
        {
            if( 2 != e.size() ) continue;

            auto x = GetRoot( e.front(), root );
            auto y = GetRoot( e.back(), root );

            if( x == y ) return e;

            if( !size.count(x) ) size[x] = 1;
            if( !size.count(y) ) size[y] = 1;

            if( size.at(x) >= size.at(y) )
            {
                size[x] += size[y];
                root[y] = x;
            }
            else
            {
                size[y] += size[x];
                root[x] = y;
            }
        }

        return {};
    }
};
