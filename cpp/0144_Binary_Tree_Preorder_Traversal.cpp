/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if( !root ) return {};

        std::stack<TreeNode*> node_stack{{root}};
        std::vector<int> ans;

        while( !node_stack.empty() )
        {
            auto curr_node = node_stack.top();
            node_stack.pop();
            ans.push_back( curr_node->val );

            if( curr_node->right ) node_stack.push( curr_node->right );
            if( curr_node->left ) node_stack.push( curr_node->left );
        }

        return ans;
    }
};
