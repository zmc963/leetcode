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
    bool FindTargetImp( TreeNode* root, int k, std::unordered_set<int>& hash ) const
    {
        if( !root ) return false;

        if( hash.count(k-root->val) ) return true;

        hash.insert(root->val);

        return FindTargetImp( root->left, k, hash ) || FindTargetImp( root->right, k, hash );
    }

    void InorderTraversal( TreeNode* root, std::vector<int>& traversal ) const
    {
        if( !root ) return;

        InorderTraversal( root->left, traversal );

        traversal.push_back( root->val );

        InorderTraversal( root->right, traversal );
    }

public:
    bool findTarget(TreeNode* root, int k)
    {
        // normal binary tree
        // std::unordered_set<int> hash;
        // return FindTargetImp( root, k, hash );

        // exploit BST
        if( !root ) return false;

        std::vector<int> traversal;
        InorderTraversal( root, traversal );

        using SIZE_TYPE = std::vector<int>::size_type;
        const auto SIZE = traversal.size();
        SIZE_TYPE left = 0;
        SIZE_TYPE right = SIZE-1;

        while( right<SIZE && left<right )
        {
            auto sum = traversal.at(left) + traversal.at(right);

            if( sum < k ) ++left;
            else if( sum > k ) --right;
            else return true;
        }

        return false;
    }
};
