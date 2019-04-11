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
    int SumOfLeftLeavesImp( const TreeNode* const root ) const
    {
        if( !root ) return 0;

        if( root->left && !root->left->left && !root->left->right )
        {
            return root->left->val + SumOfLeftLeavesImp( root->right );
        }

        return SumOfLeftLeavesImp( root->left ) + SumOfLeftLeavesImp( root->right );
    }

public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        return SumOfLeftLeavesImp(root);
    }
};
