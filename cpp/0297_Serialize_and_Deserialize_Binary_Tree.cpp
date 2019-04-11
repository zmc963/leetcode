/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
    TreeNode* DeserializeImp( std::istringstream& is ) const
    {
        std::string val;
        is >> val;

        if( "#" == val ) return nullptr;

        auto new_node = new TreeNode(std::stoi(val));
        new_node->left = DeserializeImp( is );
        new_node->right = DeserializeImp( is );

        return new_node;
    }

public:

    // Encodes a tree to a single string.
    string serialize( TreeNode* root )
    {
        if( !root ) return "#";

        auto&& left = serialize( root->left );
        auto&& right = serialize( root->right );

        assert( !left.empty() );
        assert( !right.empty() );

        return std::to_string(root->val) + " " + std::move(left) + " " + std::move(right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize( std::string data )
    {
        std::istringstream is(data);
        return DeserializeImp( is );
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
