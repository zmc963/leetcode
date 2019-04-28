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
    TreeNode* AddOneRowImp( TreeNode* root, int newValue, int targetLevel, int currLevel, bool fromLeft ) const
    {
        if( targetLevel == currLevel )
        {
            auto new_node = new TreeNode(newValue);
            // new_node->left = fromLeft ? root : nullptr;
            // new_node->right = fromLeft ? nullptr : root;

            (fromLeft ? new_node->left : new_node->right) = root;
            return new_node;
        }

        if( !root ) return nullptr;

        root->left = AddOneRowImp( root->left, newValue, targetLevel, currLevel+1, true );
        root->right = AddOneRowImp( root->right, newValue, targetLevel, currLevel+1, false );

        return root;
    }

public:
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if( d <= 0 ) return root;

        return AddOneRowImp( root, v, d, 1, true ); // true by problem definition
    }
};
