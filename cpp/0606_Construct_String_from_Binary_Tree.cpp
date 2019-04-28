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
    std::string Tree2strImp( TreeNode* t ) const
    {
        if( !t ) return {};
        if( !t->left && !t->right ) return std::to_string(t->val);

        auto left = t->left ? "("+ Tree2strImp(t->left) + ")" : "()";
        auto right = t->right ? "("+ Tree2strImp(t->right) + ")" : "";

        return std::to_string(t->val) + left + right;
    }

public:
    string tree2str(TreeNode* t)
    {
        return Tree2strImp( t );
    }
};
