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
    struct Res
    {
        int m_sum = 0;
        int m_tree_tilt = 0;
    };

    Res FindTiltImp( TreeNode* root ) const
    {
        if( !root ) return {};

        auto left = FindTiltImp( root->left );
        auto right = FindTiltImp( root->right );

        auto curr_node_tilt = std::abs( left.m_sum - right.m_sum );
        return {root->val+left.m_sum+right.m_sum, curr_node_tilt+left.m_tree_tilt+right.m_tree_tilt};
    }

public:
    int findTilt(TreeNode* root)
    {
        return FindTiltImp( root ).m_tree_tilt;
    }
};
