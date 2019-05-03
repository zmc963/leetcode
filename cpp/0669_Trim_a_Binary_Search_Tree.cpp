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
    bool IsValInRange( int L, int R, int val ) const
    {
        assert( L <= R );

        return val>=L && val<=R;
    }

    void DeepDelete( TreeNode* root ) const
    {
        if( !root ) return;

        DeepDelete( root->left );
        DeepDelete( root->right );

        delete root;
    }

    TreeNode* TrimBSTImp( TreeNode* root, int L, int R ) const
    {
        if( !root ) return nullptr;

        if( IsValInRange( L, R, root->val ) )
        {
            root->left = TrimBSTImp( root->left, L, R );
            root->right = TrimBSTImp( root->right, L, R );

            return root;
        }
        else
        {
            TreeNode* new_root = nullptr;
            if( root->val > R )
            {
                new_root = TrimBSTImp( root->left, L, R );
                // DeepDelete( root->right );
            }
            else
            {
                new_root = TrimBSTImp( root->right, L, R );
                // DeepDelete( root->left );
            }

            // delete root;
            return new_root;
        }
    }

public:
    TreeNode* trimBST(TreeNode* root, int L, int R)
    {
        if( L > R ) return nullptr;

        return TrimBSTImp( root, L, R );
    }
};

