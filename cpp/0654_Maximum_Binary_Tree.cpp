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
    using SIZE_TYPE = std::vector<int>::size_type;

    // [left, right)
    TreeNode* ConstructMaximumBinaryTreeImp( std::vector<int>& nums, SIZE_TYPE left, SIZE_TYPE right ) const
    {
        assert( left <= nums.size() );
        assert( right <= nums.size() );

        if( left >= right ) return nullptr;

        auto max_itr = std::max_element( nums.begin()+left, nums.begin()+right );

        auto new_node = new TreeNode( *max_itr );
        new_node->left = ConstructMaximumBinaryTreeImp( nums, left, max_itr-nums.begin() );
        new_node->right = ConstructMaximumBinaryTreeImp( nums, max_itr-nums.begin()+1, right );

        return new_node;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return ConstructMaximumBinaryTreeImp( nums, 0, nums.size() );
    }
};
