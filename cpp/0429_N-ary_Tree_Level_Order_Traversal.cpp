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
    void LevelOrderTraversal( const Node* const root, int level, std::vector<std::vector<int>>& ans ) const
    {
        if( !root ) return;
        if( level >= ans.size() ) ans.push_back({});

        ans.at(level).push_back( root->val );

        for( auto c : root->children )
        {
            LevelOrderTraversal( c, level+1, ans );
        }
    }

public:
    vector<vector<int>> levelOrder(Node* root)
    {
        std::vector<std::vector<int>> ans;
        LevelOrderTraversal( root, 0, ans );

        return ans;
    }
};
