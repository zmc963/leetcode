/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    using SIZE_TYPE = std::vector<std::string>::size_type;

    int MaxDepth( TreeNode* root ) const
    {
        if( !root ) return 0;

        return 1 + std::max( MaxDepth(root->left), MaxDepth(root->right) );
    }

    // [left, right)
    void PrintTreeImp( TreeNode* root, int level, SIZE_TYPE left, SIZE_TYPE right, std::vector<std::vector<std::string>>& ans ) const
    {
        if( !root || left>=right ) return;

        auto mid = (left+right) / 2;
        ans.at(level).at(mid) = std::to_string(root->val);

        PrintTreeImp( root->left, level+1, left, mid, ans );
        PrintTreeImp( root->right, level+1, mid+1, right, ans );
    }

public:
    vector<vector<string>> printTree(TreeNode* root)
    {
        if( !root ) return {};

        auto max_depth = MaxDepth( root );
        assert( 1 <= max_depth );
        auto col_len = std::pow(2, max_depth) - 1;
        std::vector<std::vector<std::string>> ans( max_depth, std::vector<string>(col_len) );

        PrintTreeImp( root, 0, 0, col_len, ans );

        return ans;
    }
};
