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
    int LongestUnivaluePathImp( TreeNode* root, int& maxLen ) const
    {
        if( !root ) return 0;

        auto left = LongestUnivaluePathImp( root->left, maxLen );
        auto right = LongestUnivaluePathImp( root->right, maxLen );

        left = (root->left && root->val==root->left->val) ? left+1 : 0;
        right = (root->right && root->val==root->right->val) ? right+1 : 0;

        maxLen = std::max( maxLen, left+right );

        return std::max(left, right);
    }

public:
    int longestUnivaluePath(TreeNode* root)
    {
        auto max_len = 0;
        LongestUnivaluePathImp( root, max_len );

        return max_len;
    }
};
