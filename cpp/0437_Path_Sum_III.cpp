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
    int PathSumImp(TreeNode* root, int sum) const
    {
        if( !root ) return 0;

        auto left = PathSumImp( root->left, sum-root->val );
        auto right = PathSumImp( root->right, sum-root->val );

        return (sum==root->val) + left + right;
    }

public:
    int pathSum(TreeNode* root, int sum) const
    {
        if( !root ) return 0;

        auto curr = PathSumImp( root, sum );

        auto left = pathSum( root->left, sum );
        auto right = pathSum( root->right, sum );

        return curr + left + right;
    }
};
