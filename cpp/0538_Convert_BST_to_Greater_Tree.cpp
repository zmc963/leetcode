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
    void ConvertBSTImp( TreeNode* root, int& currSum ) const
    {
        if( !root ) return;

        ConvertBSTImp( root->right, currSum );

        currSum += root->val;
        root->val = currSum;

        ConvertBSTImp( root->left, currSum );
    }

public:
    TreeNode* convertBST(TreeNode* root)
    {
        auto curr_sum = 0;
        ConvertBSTImp( root, curr_sum );

        return root;
    }
};
