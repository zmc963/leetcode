class Solution
{
    int CountUnivalSubtreesImp( TreeNode* root, bool& isUni ) const
    {
        if( !root )
        {
            isUni = true;
            return 0;
        }

        bool isLeftUni = false;
        bool isRightUni = false;
        auto count = countUnivalSubtrees(root->left, isLeftUni) + countUnivalSubtrees(root->right, isRightUni);

        bool is_left_uni = isLeftUni && root->left && root->val==root->left->val;
        bool is_right_uni = isRightUni && root->right && root->val==root->right->val;

        isUni = false;
        if( root->left && root->right )
        {
            if( is_left_uni && is_right_uni )
            {
                isUni = true;
                ++count;
            }
        }
        else if( root->left )
        {
            if( is_left_uni )
            {
                isUni = true;
                ++count;
            }
        }
        else if( root->right )
        {
            if( is_right_uni )
            {
                isUni = true;
                ++count;
            }
        }
        else
        {
            isUni = true;
            ++count;
            assert( 1 == count );
        }

        return count;
    }

public:
    // note !!!! not submitted, this is just a guess
    int countUnivalSubtrees( TreeNode* root ) const
    {
	bool is_uni = false;
        return CountUnivalSubtreesImp( root, is_uni );
    }
};
