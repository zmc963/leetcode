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
    std::string FindDuplicateSubtrees( TreeNode* node, std::unordered_map<std::string, int>& hash, std::vector<TreeNode*>& ans ) const
    {
        if( !node ) return "#";

        auto left_encoded = FindDuplicateSubtrees( node->left, hash, ans );
        auto right_encoded = FindDuplicateSubtrees( node->right, hash, ans );

        auto encoded = std::to_string(node->val) + "," + left_encoded + "," + right_encoded;

        if( hash[encoded]++ == 1 ) ans.push_back(node);

        return encoded;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        std::unordered_map<std::string, int> hash;
        std::vector<TreeNode*> ans;

        FindDuplicateSubtrees( root, hash, ans );

        return ans;
    }
};
