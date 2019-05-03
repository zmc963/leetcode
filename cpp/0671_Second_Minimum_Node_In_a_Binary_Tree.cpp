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
    void FindSecondMinimumValueImp( TreeNode* root, int firstMin, TreeNode*& secondMinNode ) const
    {
        if( !root ) return;

        if( (!secondMinNode || root->val<secondMinNode->val) && root->val>firstMin )
        {
            secondMinNode = root;
        }
	else if( root->val == firstMin )
	{
            FindSecondMinimumValueImp( root->left, firstMin, secondMinNode );
            FindSecondMinimumValueImp( root->right, firstMin, secondMinNode );
        }
    }

public:
    int findSecondMinimumValue( TreeNode* root )
    {
        if( !root ) return -1;

        TreeNode* second_min_node = nullptr;
        FindSecondMinimumValueImp( root, root->val, second_min_node );

        return second_min_node ? second_min_node->val : -1;
    }
};

