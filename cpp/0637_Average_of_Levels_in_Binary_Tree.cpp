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
    using SIZE_TYPE = std::vector<double>::size_type;

    void AverageOfLevelsImp( TreeNode* root, int currLevel, std::vector<double>& sum, std::vector<int>& cnt ) const
    {
        if( !root ) return;

        if( currLevel >= sum.size() )
        {
            sum.push_back( root->val );
            cnt.push_back( 1 );
        }
        else
        {
            sum.at(currLevel) += root->val;
            ++cnt.at(currLevel);
        }

        AverageOfLevelsImp( root->left, currLevel+1, sum, cnt );
        AverageOfLevelsImp( root->right, currLevel+1, sum, cnt );
    }

public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        std::vector<double> sum;
        std::vector<int> cnt;

        AverageOfLevelsImp( root, 0, sum, cnt );
        assert( sum.size() == cnt.size() );

        std::vector<double> ans;
        const auto SIZE = sum.size();
        for( SIZE_TYPE i=0; i<SIZE; ++i )
        {
            assert( 0 != cnt.at(i) );
            ans.push_back( sum.at(i) / cnt.at(i) );
        }

        return ans;
    }
};
