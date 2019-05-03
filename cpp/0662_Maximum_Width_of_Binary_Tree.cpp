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
    using NUM_TYPE = int;
    using QUQUE_TYPE = std::queue<std::pair<TreeNode*, NUM_TYPE>>;

    void WidthOfBinaryTreeImp( TreeNode* root, int num, int level, std::vector<std::pair<int, int>>& memo, int& maxWidth )
    {
        assert( num >= 1 );
        if( !root ) return;

        // std::cout << level << " " << num << std::endl;
        if( level >= memo.size() ) memo.emplace_back(num, num);
        else
        {
            memo.at(level).first = std::min( memo.at(level).first, num );
            memo.at(level).second = std::max( memo.at(level).second, num );
        }

        maxWidth = std::max( maxWidth, memo.at(level).second - memo.at(level).first + 1 );

        // conventinal heap encoding would be 2*num, 2*num+1.
        // here we use 2*num-1, 2*num would make node's num starts from 1 in every level
        // but still signed overflow..
        WidthOfBinaryTreeImp( root->left, num*2-1, level+1, memo, maxWidth );
        WidthOfBinaryTreeImp( root->right, num*2, level+1, memo, maxWidth );
    }

public:
    int widthOfBinaryTree(TreeNode* root)
    {
        // std:vector<std::pair<int, int>> memo;
        // WidthOfBinaryTreeImp( root, 1, 0, memo, max_width );

        QUQUE_TYPE node_queue;
        if( root ) node_queue.emplace( root, 1 );

        NUM_TYPE max_width = 0;
        while( !node_queue.empty() )
        {
            auto size = node_queue.size();

            bool has_val = size;
            auto min_num = std::numeric_limits<NUM_TYPE>::max();
            NUM_TYPE max_num = 0;
            auto offset = size ? node_queue.front().second-1: 0;

            while( size-- > 0 )
            {
                auto node = node_queue.front();
                node_queue.pop();

                assert( node.second >= 1 );
                min_num = std::min( min_num, node.second );
                max_num = std::max( max_num, node.second );

                // note the offset
                if( node.first->left ) node_queue.emplace( node.first->left, (node.second-offset)*2-1 );
                if( node.first->right ) node_queue.emplace( node.first->right, (node.second-offset)*2 );
            }

            if( has_val ) max_width = std::max( max_width, max_num-min_num+1 );
        }

        return max_width;
    }
};
