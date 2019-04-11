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
    void FindModeImp( TreeNode* root, TreeNode*& pre, int& currCnt, int& maxCnt, std::vector<int>& ans ) const
    {
        if( !root ) return;

        FindModeImp( root->left, pre, currCnt, maxCnt, ans );

        if( pre && pre->val==root->val )
        {
            ++currCnt;
        }
        else
        {
            currCnt = 1;
        }

        pre = root;
        if( maxCnt < currCnt )
        {
            ans.clear();
            maxCnt = currCnt;
        }

        if( maxCnt == currCnt )
        {
            ans.push_back( root->val );
        }

        FindModeImp( root->right, pre, currCnt, maxCnt, ans );
    }

public:
    vector<int> findMode(TreeNode* root)
    {
        std::unordered_map<int, int> mode;
        int max_cnt = std::numeric_limits<decltype(max_cnt)>::min();
        int curr_cnt = std::numeric_limits<decltype(curr_cnt)>::min();
        TreeNode* pre = nullptr;
        std::vector<int> ans;

        FindModeImp( root, pre, max_cnt, curr_cnt, ans );

        return ans;
    }
};
