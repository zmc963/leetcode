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
    // enum class LCA { NOT_FOUND, FOUND_ONE, FOUND_BOTH };

    TreeNode* LCA( TreeNode* root, TreeNode* p, TreeNode* q )
    {
        if( !root ) return nullptr;
        if( p==root || q==root ) return root;

        auto left = LCA( root->left, p, q );
        auto right = LCA( root->right, p, q );

        if( left && right ) return root;
        if( left ) return left;
        if( right ) return right;

        return nullptr;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return LCA( root, p, q );
    }

//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         assert( p != q && root );
//         mLCA = nullptr;
//         RecurseTree( root, p, q );

//         return mLCA;
//     }

private:
//     int RecurseTree(
//         TreeNode* const curr,
//         TreeNode* const p,
//         TreeNode* const q )
//     {
//         if( !curr ) return NOT_FOUND;

//         int left = RecurseTree( curr->left, p, q );
//         int right = RecurseTree( curr->right, p, q );
//         int mid = (p == curr || q == curr) ? FOUND_ONE : NOT_FOUND;

//         assert( !(FOUND_ONE == mid && FOUND_ONE == left && FOUND_ONE == right) );

//         if( ((FOUND_ONE == mid) && (FOUND_ONE == left || FOUND_ONE == right)) ||
//             (FOUND_ONE == left && FOUND_ONE == right) )
//         {
//             mLCA = curr;
//             return FOUND_LCA;
//         }

//         return (FOUND_ONE == left || FOUND_ONE == right || FOUND_ONE == mid) ? FOUND_ONE : NOT_FOUND;
//     }

//     static constexpr int NOT_FOUND = 0;
//     static constexpr int FOUND_ONE = 1;
//     static constexpr int FOUND_LCA = 1;
//     TreeNode* mLCA = nullptr;
};
