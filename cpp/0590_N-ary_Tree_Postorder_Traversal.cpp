/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    vector<int> postorder(Node* root)
    {
        if( !root ) return {};

        std::stack<Node*> node_stack{{root}};
        std::vector<int> ans;

        while( !node_stack.empty() )
        {
            auto curr_node = node_stack.top();
            node_stack.pop();
            ans.push_back( curr_node->val );

            for( auto&& c : curr_node->children )
            {
                if( c ) node_stack.push( c );
            }
        }

        std::reverse( ans.begin(), ans.end() );

        return ans;
    }
};
