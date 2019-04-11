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
public:
    int maxDepth(Node* root)
    {
        if( !root ) return 0;

        auto depth = 0;
        for( auto n : root->children )
        {
            depth = std::max( depth, maxDepth(n) );
        }

        return 1 + depth;
    }
};
