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
//     int GetSum( TreeNode* root ) const
//     {
//         if( !root ) return 0;

//         return root->val + GetSum( root->left ) + GetSum( root->right );
//     }

    int FindFrequentTreeSumImp( TreeNode* root, std::unordered_map<int, int>& sumCnt, int& maxCnt, std::vector<int>& ans ) const
    {
        if( !root ) return 0;

        auto left = FindFrequentTreeSumImp( root->left, sumCnt, maxCnt, ans );
        auto right = FindFrequentTreeSumImp( root->right, sumCnt, maxCnt, ans );

        auto curr_sum = left + right + root->val;
        auto new_cnt = ++sumCnt[curr_sum];

        if( maxCnt <= new_cnt )
        {
            if( maxCnt < new_cnt ) ans.clear();

            maxCnt = new_cnt;
            ans.emplace_back( curr_sum );
        }

        return curr_sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        std::unordered_map<int, int> sum_cnt;
        int max_cnt = 0;
        std::vector<int> ans;
        FindFrequentTreeSumImp( root, sum_cnt, max_cnt, ans );

        return ans;
    }
};

