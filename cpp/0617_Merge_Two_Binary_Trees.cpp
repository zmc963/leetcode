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
    TreeNode* Deepcopy( TreeNode* node ) const
    {
        if( !node ) return nullptr;

        auto new_node = new TreeNode( node->val );
        new_node->left = Deepcopy( node->left );
        new_node->right = Deepcopy( node->right );

        return new_node;
    }

public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if( !t1 && !t2 ) return nullptr;
        else if( !t1 ) return Deepcopy( t2 );
        else if( !t2 ) return Deepcopy( t1 );

        auto new_node = new TreeNode( t1->val + t2->val );
        new_node->left = mergeTrees( t1->left, t2->left );
        new_node->right = mergeTrees( t1->right, t2->right );

        return new_node;
    }
};
