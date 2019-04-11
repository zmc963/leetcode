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
    int GetDiameterOfBinaryTree( TreeNode* curr, int& diameter ) const
    {
        if( !curr ) return 0;

        auto left = GetDiameterOfBinaryTree(curr->left, diameter);
        auto right = GetDiameterOfBinaryTree(curr->right, diameter);

        diameter = std::max( diameter, left+right );

        return 1 + std::max( left, right );
    }

public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        auto diameter = 0;
        GetDiameterOfBinaryTree( root, diameter );

        return diameter;
    }
};
