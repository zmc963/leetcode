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
    std::pair<TreeNode*, int> SubtreeWithAllDeepestImp( TreeNode* root, int currDepth ) const
    {
        assert( currDepth >=0 );
        if( !root ) return {nullptr, 0};

        auto left = SubtreeWithAllDeepestImp( root->left, currDepth );
        auto right = SubtreeWithAllDeepestImp( root->right, currDepth );

        if( left.second == right.second ) return {root, left.second+1};
        else if( left.second > right.second ) return {left.first, left.second+1};
        return {right.first, right.second+1};
    }

public:
    TreeNode* subtreeWithAllDeepest( TreeNode* root )
    {
        return SubtreeWithAllDeepestImp( root, 0 ).first;
    }
};
