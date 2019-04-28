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
class Solution
{
    using SIZE_TYPE = std::vector<int>::size_type;

public:
    vector<int> preorder(Node* root)
    {
        if( !root ) return {};

        std::stack<Node*> node_stack{{root}};
        std::vector<int> ans;

        while( !node_stack.empty() )
        {
            auto curr_node = node_stack.top();
            node_stack.pop();

            ans.push_back( curr_node->val );

            if( !curr_node->children.empty() )
            {
                const auto SIZE = curr_node->children.size();
                for( SIZE_TYPE i=SIZE-1; i<SIZE; --i )
                {
                    auto node = curr_node->children.at(i);
                    if( node ) node_stack.push( node );
                }
            }
        }

        return ans;
    }
};
