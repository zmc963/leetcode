/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution
{
    int DFS(
        const std::unordered_map<int, Employee*>& graph,
        int ID ) const
    {
        if( !graph.count(ID) ) return 0;

        auto val = graph.at(ID)->importance;
        for( auto sub_ID : graph.at(ID)->subordinates )
        {
            val += DFS( graph, sub_ID );
        }

        return val;
    }

public:
    int getImportance(vector<Employee*> employees, int id)
    {
        std::unordered_map<int, Employee*> graph;
        for( auto e : employees ) graph[e->id] = e;

        return DFS( graph, id );
    }
};
