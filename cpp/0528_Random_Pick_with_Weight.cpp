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
    void GetMinimumDifferenceImp( TreeNode* root, TreeNode*& pre, int& minDiff ) const
    {
        if( !root ) return;

        GetMinimumDifferenceImp( root->left, pre, minDiff );

        if( pre ) minDiff = std::min( minDiff, std::abs(pre->val - root->val) );
        pre = root;

        GetMinimumDifferenceImp( root->right, pre, minDiff );
    }

public:
    int getMinimumDifference(TreeNode* root)
    {
        int min_diff = std::numeric_limits<decltype(min_diff)>::max();
        TreeNode* pre = nullptr;
        GetMinimumDifferenceImp( root, pre, min_diff );

        return min_diff;
    }
};
