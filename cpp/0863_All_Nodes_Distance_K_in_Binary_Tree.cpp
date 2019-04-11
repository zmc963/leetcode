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
    void GetDistanceKNodes( TreeNode* root, int K, std::vector<int>& ans ) const
    {
        if( K<0 || !root ) return;

        if( 0 == K )
        {
            ans.push_back( root->val );
            return;
        }

        GetDistanceKNodes( root->left, K-1, ans );
        GetDistanceKNodes( root->right, K-1, ans );
    }

    bool DistanceKImp( TreeNode* root, TreeNode* target, int& K, std::vector<int>& ans ) const
    {
        if( !root ) return false;

        if( root == target )
        {
            GetDistanceKNodes( target, K, ans );
            return true;
        }

        if( DistanceKImp( root->left, target, K, ans ) )
        {
            --K;
            if( 0 == K ) ans.push_back( root->val );
            else GetDistanceKNodes( root->right, K-1, ans );

            return true; // we can return false, but ture means we don't need to do tree traveral anymore(or simply means we've got found the target, and now we're collecting nodes), just care about the path up to root, so it will be faster
        }

        if( DistanceKImp( root->right, target, K, ans ) )
        {
            --K;
            if( 0 == K ) ans.push_back( root->val );
            else GetDistanceKNodes( root->left, K-1, ans );

            return true;
        }

        return false;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {
        std::vector<int> ans;
        DistanceKImp( root, target, K, ans ) ;

        return ans;
    }
};
