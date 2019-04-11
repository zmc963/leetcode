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
    using SIZE_TYPE = std::string::size_type;

    TreeNode* DeserializeImp( std::istringstream& is, TreeNode* minNode, TreeNode* maxNode ) const
    {
        if( std::istringstream::traits_type::eof() == is.peek() ) return nullptr; // not peek.eof()...

        // peek next element
        auto ori_pos = is.tellg();
        std::string val;
        is >> val;
        auto curr_val = std::stoi(val);

        if( !((minNode && maxNode && curr_val<maxNode->val && curr_val>minNode->val) ||
              (!minNode && maxNode && curr_val<maxNode->val) ||
              (minNode && !maxNode && curr_val>minNode->val) ||
              (!minNode && !maxNode)) )
        {
            is.seekg(ori_pos);
            return nullptr;
        }

        auto new_node = new TreeNode(curr_val);
        new_node->left = DeserializeImp( is, minNode, new_node );
        new_node->right = DeserializeImp( is, new_node, maxNode );

        return new_node;
    }

public:
    // Encodes a tree to a single string.
    string serialize( TreeNode* root )
    {
        if( !root ) return {};

        auto&& left = serialize( root->left );
        auto&& right = serialize( root->right );

        if( !left.empty() ) left = " " + left;
        if( !right.empty() ) right = " " + right;

        return std::to_string(root->val) + std::move(left) + std::move(right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize( std::string data )
    {
        std::istringstream is(data);
        return DeserializeImp( is, nullptr, nullptr );
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
