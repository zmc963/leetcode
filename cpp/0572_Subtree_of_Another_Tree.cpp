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
    bool IsSametree( TreeNode* s, TreeNode* t ) const
    {
        if( !s && !t ) return true;
        else if( !s || !t ) return false;

        return s->val==t->val && IsSametree( s->left, t->left ) && IsSametree( s->right, t->right );
    }

public:
    bool isSubtree( TreeNode* s, TreeNode* t ) const
    {
        if( !s || !t ) return false;

        if( s->val==t->val && IsSametree( s, t ) )
        {
            return true;
        }

        return isSubtree( s->left, t ) || isSubtree( s->right, t );
    }
};
