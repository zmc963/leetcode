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
    TreeNode* GetMinValParentNode( TreeNode* root ) const
    {
        if( !root ) return nullptr;
        if( !root->left ) return root;
        if( root->left && !root->left->left ) return root;

        return GetMinValParentNode( root->left );
    }

public:
    TreeNode* deleteNode( TreeNode* root, int key )
    {
        if( !root ) return nullptr;

        if( key > root->val )
        {
            root->right = deleteNode( root->right, key );
        }
        else if( key < root->val )
        {
            root->left = deleteNode( root->left, key );
        }
        else
        {
            TreeNode* new_root = nullptr;
            if( root->right )
            {
                new_root = root->right;
                while (new_root->left)
                {
                    new_root = new_root->left;
                }
                new_root->left = root->left;
                new_root = root->right;
            }
            else
            {
                new_root = root->left;
            }

            delete root;
            return new_root;
        }

        return root;
    }
};
