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
    void LargestValuesImp( TreeNode* root, int level, std::vector<int>& ans ) const
    {
        if( !root ) return;

        if( level >= ans.size() )
        {
            ans.push_back( root->val );
        }
        else
        {
            ans.at(level) = std::max( ans.at(level), root->val );
        }

        LargestValuesImp( root->left, level+1, ans );
        LargestValuesImp( root->right, level+1, ans );
    }

public:
    vector<int> largestValues(TreeNode* root)
    {
        std::vector<int> ans;
        LargestValuesImp( root, 0, ans );

        return ans;
    }
};
