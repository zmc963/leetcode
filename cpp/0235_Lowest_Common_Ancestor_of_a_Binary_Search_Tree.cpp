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
    TreeNode* LowestCommonAncestorImp( TreeNode* root, TreeNode* p, TreeNode* q ) const
    {
        if( !root ) return nullptr;

        auto p_val = p->val;
        auto q_val = q->val;
        auto root_val = root->val;

        if( p_val>root_val && q_val>root_val )
        {
            return LowestCommonAncestorImp( root->right, p, q );
        }
        else if( p_val<root_val && q_val<root_val )
        {
            return LowestCommonAncestorImp( root->left, p, q );
        }

        return root;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if( !root || !p || !q ) return nullptr;

        return LowestCommonAncestorImp( root, p, q );
    }
};
