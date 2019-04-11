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
    void FindBottomLeftValueImp( TreeNode* root, int level, int& maxLevel, int& ans ) const
    {
        if( !root ) return;

        if( maxLevel < level )
        {
            maxLevel = level;
            ans = root->val;
        }

        FindBottomLeftValueImp( root->left, level+1, maxLevel, ans );
        FindBottomLeftValueImp( root->right, level+1, maxLevel, ans );
    }

public:
    int findBottomLeftValue(TreeNode* root)
    {
        int ans = -1;
        int max_level = -1;
        FindBottomLeftValueImp( root, 0, max_level, ans );

        return ans;
    }
};
