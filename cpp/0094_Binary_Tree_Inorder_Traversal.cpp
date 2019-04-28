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
    vector<int> inorderTraversal(TreeNode* root)
    {
        std::stack<TreeNode*> node_stack;
        auto curr_node = root;

        std::vector<int> ans;
        while( curr_node || !node_stack.empty() )
        {
            while( curr_node )
            {
                node_stack.push( curr_node );
                curr_node = curr_node->left;
            }

            curr_node = node_stack.top();
            ans.push_back( curr_node->val );
            node_stack.pop();

            curr_node = curr_node->right;
        }

        return ans;
    }
};
